-- Favorite Food
-- Print out your favorite food
favFood = putStrLn "Crab Legs"

-- Number Exercise
-- Write 5 examples of expressions using operations
someOperations = do
  print $ 4 + 2.5
  print $ 4 * 2
  print $ 4 / 2
  print $ 4 / 2.4
  print $ 5 `mod` 2
  print $ 2.3 - 1.333

-- Boolean Exercise
-- Write some examples of expressions using logic operations
boolsExample = do
  print $ True == True
  print $ True == False
  print $ True
  print $ True && False
  print $ True || False
  print $ True && True

-- Variables Exercise
-- Declare a cariable called "firstName" and "lastName" yaddy yadda
firstName :: String
firstName = "David"
lastName :: String
lastName = "Rogers"
fullName :: String
fullName = concat [firstName, " ", lastName]
varsExample = do
  print $ concat [firstName, " ", lastName]
  print fullName

-- Strings Exercise
-- Show concatenation and find string length
newString :: String
newString = concat ["Hello,", " ", "World"]
stringLength :: Int
stringLength = length newString
calculateLength = print stringLength

-- Goodbye (*)
-- Write a function that takes a string and returns a string saying
-- bye to that name
goodbye :: String -> String
goodbye s = "Goodbye, " ++ s

-- Plus Five
-- Write a function plusFive that takes in a number as an argument
-- and returns the sum + 5.
plusFive :: Int -> Int
plusFive x = x + 5
