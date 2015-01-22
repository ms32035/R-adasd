
test_that("Value correctness",{
  expect_equivalent(shortestpath(matrix(c(0,0,1,0),nrow=2),1,2),1)
  expect_equivalent(shortestpath(matrix(c(0,1,0,0),nrow=2),1,2),999999999)
})
