\name{kursaweManager}
\alias{kursaweManager}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Manager for objective selection
}
\description{
The manager decides the objective to evaluate in worker
}
\usage{
kursaweManager(workerID, x)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{workerID}{
%%     ~~Describe \code{workerID} here~~
}
  \item{x}{
%%     ~~Describe \code{x} here~~
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
%%  ~~who you are~~
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
function (workerID, x) 
{
    if (workerID == 1) {
        return(kursaweObj1(x))
    }
    else {
        return(kursaweObj2(x))
    }
  }
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ parallel }
\keyword{ snow }% __ONLY ONE__ keyword per line
