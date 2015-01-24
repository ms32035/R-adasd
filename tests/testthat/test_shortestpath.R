test_that("Input values",{
  expect_error(shortestpath(matrix(c(0,0,2,0),nrow=2),1,2))
  expect_error(shortestpath(matrix(c(0,0,1,0),nrow=2),0,2))
  expect_error(shortestpath(matrix(c(0,0,1,0),nrow=2),1,3))
})
G100 <- matrix(rep(1,10000),nrow=100)
G4 <- matrix(c(0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0),nrow=4)
test_that("Value correctness",{
  expect_equivalent(shortestpath(matrix(c(0,0,1,0),nrow=2),1,2),1)
  expect_equivalent(shortestpath(matrix(c(0,1,0,0),nrow=2),1,2),999999999)
  expect_equivalent(shortestpath(G4,1,4),2)
})
