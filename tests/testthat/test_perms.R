test_that("Input values",{
  expect_error(perms("a"))         
})
test_that("Value correctness",{
  expect_equivalent(perms(1),(matrix(c(1),nrow=1)))
  expect_equivalent(perms(2),(matrix(c(1,2,2,1),nrow=2)))
  expect_equal(nrow(perms(6)),factorial(6))
  expect_equal(all(perms(5) %in% c(1,2,3,4,5)),TRUE)
})
