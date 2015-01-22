test_that("Input values",{
  expect_error(mode("a"))
  expect_error(mode(c("a",1)))         
})

test_that("Value correctness",{
  expect_equivalent(mode(c(1,1,1,1)),1)
  expect_equivalent(mode(c(1,1,1,2)),1)
  expect_equivalent(mode(c(1,2,2,2)),2)
})