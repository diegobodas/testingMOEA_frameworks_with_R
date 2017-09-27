library (snow)
library (kursaweMO)

#start the cluster
cluster <- makeCluster(type = "SOCK", c("localhost", "localhost"))

x <- c(1.0, 2.0, 3.0)

result<- clusterApply(cluster, 1:2, kursaweManager, x)

stopCluster(cluster)