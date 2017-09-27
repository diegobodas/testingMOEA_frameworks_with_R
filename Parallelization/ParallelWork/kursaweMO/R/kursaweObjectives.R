kursaweObj1 <- function (x) {
  myResult<-0
  for (i in 1:(length(x)-1)) { 
    myResult <- myResult + (-10.0 * exp(-0.2 * sqrt((x[i])^(2.0) + (x[i+1])^(2.0))))
  }
  
  return (myResult)
}
 
kursaweObj2 <- function (x) {
  myResult<-0
  for (i in 1:(length(x))) { 
    myResult <- myResult + (abs(x[i])^(0.8)) + 5.0 * sin((x[i])^(3.0))
  }
  
  return (myResult)
}

kursaweManager <- function(workerID, x) {
  if (workerID == 1) {
    return (kursaweObj1(x))
  }
  else {
    return (kursaweObj2(x))
  }
}