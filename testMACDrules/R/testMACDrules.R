#Reference: http://blog.revolutionanalytics.com/2009/05/parallelized-backtesting-with-foreach.html

#Define a MACD trading rule. Takes a buy position of the long instrument
#is signal >0 (converting into the benchmark instrument on the sell signal)
#typeMA = Simple Moving Average (SMA) or Exponential Moving Average (EMA)
simpleRule2 <- function(z, fast, slow, signal, long, benchmark, typeMA) {
  library(TTR)
  x <- MACD(z, nFast=fast, nSlow=slow, nSig=signal, maType=typeMA)
  position <- sign(x[,1]-x[,2])
  s <- xts(position, order.by=index(z))
  return (long * (s>0) + benchmark * (s<=0))
}

sharpeRatio <- function (z, fast, slow, signal, long, benchmark, typeMA) {
  Return <- simpleRule2(z$SP500, fast, slow, signal, long, benchmark, typeMA)
  Dt <- na.omit (Return - benchmark)
  sharpe <- mean(Dt)/sd(Dt)
  return (sharpe)
}

simpleRuleRiskReturnManager <- function(workerID, z, fast, slow, signal, long, benchmark) {
  if (workerID == 1) {
    return (sharpeRatio(z$SP500, fast, slow, signal, long, benchmark, "SMA")) 
  }
  else {
    return (sharpeRatio(z$SP500, fast, slow, signal, long, benchmark, "EMA"))
  }
}