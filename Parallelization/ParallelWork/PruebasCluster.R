library (snow)
x <- c(1, 2, 3)
myresult <- function(workerID, x) {
  if (workerID == 1){
    print (paste ("Worker", workerID))
    return (2*x)
  }
  else{
    print (paste ("Worker", workerID))
    return (5*x)
  }
}
#start the cluster
cl <- makeCluster(type = "SOCK", c("localhost", "localhost"))

clusterApply (cl, seq (along = cl), function(id) WORKER.ID <<-id)
resultados <- clusterApply(cl, 1:2, myresult, x)
print (paste ("resultados", resultados))
stopCluster(cl)