\name{kursaweObj1}
\alias{kursaweObj1}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Objective 1 in kursawe function
}
\description{
Kursawe --- objective 1
}
\usage{
kursaweObj1(x)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
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
function (x) 
{
    myResult <- 0
    for (i in 1:(length(x) - 1)) {
        myResult <- myResult + (-10 * exp(-0.2 * sqrt((x[i])^(2) + 
            (x[i + 1])^(2))))
    }
    return(myResult)
  }
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ kursawe }
\keyword{ snow }% __ONLY ONE__ keyword per line
