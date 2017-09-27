\name{simpleRuleRiskReturnManager}
\alias{simpleRuleRiskReturnManager}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Testing EMA and SMA for MACD
}
\description{
Testing EMA and SMA for MACD
}
\usage{
simpleRuleRiskReturnManager(workerID, z, fast, slow, signal, long, benchmark)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{workerID}{
The worker ID in a cluster environment or the Sharpe Ration to test
}
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
function (workerID, z, fast, slow, signal, long, benchmark) 
{
    if (workerID == 1) {
        return(sharpeRatio(z$SP500, fast, slow, signal, long, 
            benchmark, "SMA"))
    }
    else {
        return(sharpeRatio(z$SP500, fast, slow, signal, long, 
            benchmark, "EMA"))
    }
  }
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ MACD }
\keyword{ Sharpe }% __ONLY ONE__ keyword per line
