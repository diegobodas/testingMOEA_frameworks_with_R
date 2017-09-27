\name{sharpeRatio}
\alias{sharpeRatio}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Calculate the Sharpe Ratio of z}
\description{Calculate the Sharpe Ratio of z}
\usage{
sharpeRatio(z, fast, slow, signal, long, benchmark, typeMA)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{z}{
Data example sp500
}
  \item{fast}{
fast parameter for MACD rule
}
  \item{slow}{
slow parameter for MACD rule
}
  \item{signal}{
signal parameter for MACD rule
}
  \item{long}{
to be long in
}
  \item{benchmark}{
for short position
}
  \item{typeMA}{
EMA or SMA
}
}
\details{
%%  ~~ If necessary, more details than the description above ~~
}
\value{
%%  ~Describe the value returned
%%  If it is a LIST, use
%%  \item{comp1 }{Description of 'comp1'}
%%  \item{comp2 }{Description of 'comp2'}
%% ...
}
\references{
%% ~put references to the literature/web site here ~
}
\author{
Diego J Bodas Sagi
}
\note{
%%  ~~further notes~~
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
%% ~~objects to See Also as \code{\link{help}}, ~~~
}
\examples{
##---- Should be DIRECTLY executable !! ----
##-- ==>  Define data, use random,
##--	or do  help(data=index)  for the standard data sets.

## The function is currently defined as
function (z, fast, slow, signal, long, benchmark, typeMA) 
{
    Return <- simpleRule2(z$SP500, fast, slow, signal, long, 
        benchmark, typeMA)
    Dt <- na.omit(Return - benchmark)
    sharpe <- mean(Dt)/sd(Dt)
    return(sharpe)
  }
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ Sharpe }
\keyword{ MACD }% __ONLY ONE__ keyword per line
