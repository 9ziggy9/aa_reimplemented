import System.Posix (SystemID(version))
import Data.Char (toLower)
import Data.List (isInfixOf, isPrefixOf, isSuffixOf)

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
  print True
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


-- Whisper
-- Write a function that takes a string and returns whispered version
-- We map toLower over string
whisper :: String -> String
whisper s = "..." ++ map toLower s ++ "..."

-- Averager
-- Function which returns average of list of nums
averager :: [Float] -> Float
averager xs = sum xs / fromIntegral (length xs);

-- Is Odd
-- Function determines if number is odd or not
isOdd :: Int -> Bool
isOdd n
  | odd n = True
  | otherwise = False

-- Log Between
-- Print every number between a low and high value
logBetween :: Int -> Int -> [Int]
logBetween a b = [a..b]

-- Print Fives
-- Function to print out multiple of fives in range
printFives :: Int -> Int -> [Int]
printFives a b = [x | x <- [a..b], x `mod` 5 == 0]

-- Add Arrays
-- Write function that returns two combined arrays
combineArrays :: [Int] -> [Int] -> [Int]
combineArrays as bs = as ++ bs

-- Doubler
doubleList :: [Int] -> [Int]
doubleList xs = [2*x | x <- xs]

-- Vowel Counter
isVowel :: Char -> Bool
isVowel c = c `elem` "aeiou"

vowelCounter :: String -> Int
vowelCounter s = length $ filter isVowel s

-- Testing IO monad
promptCountVowels :: IO ()
promptCountVowels = do
  putStrLn "Enter a string to count vowels: "
  s <- getLine
  print (vowelCounter s)

-- Is Substring
-- Check if given string is substring of other
isSubstring :: String -> String -> Bool
isSubstring = isInfixOf

-- Fizz Buzz
fizzBuzzOut :: Int -> String
fizzBuzzOut k
  | k `mod` 5 == 0 && k `mod` 3 == 0 = "Fizz Buzz"
  | k `mod` 3 == 0 = "Fizz"
  | k `mod` 5 == 0 = "Buzz"
  | otherwise = show k

fizzBuzz :: Int -> [String]
fizzBuzz max = map fizzBuzzOut [1..max]

-- Pig Latin
-- Takes a string and out puts it in pig latin
-- NOTE: Remember that using head/tail here would be UNSAFE
startsVowel :: String -> Bool
startsVowel (c:_)
  | c `elem` "aeiou" = True
  | otherwise = False

word2Pig :: String -> String
word2Pig w
  | startsVowel w = w ++ "yay"
  | otherwise = go w where
      go (c:cs)
        | not $ startsVowel (c:cs) = go (cs ++ [c])
        | otherwise = (c:cs) ++ "ay"

toPig :: String -> String
toPig = unwords . map word2Pig . words

-- Pig Latin (break/span)
-- Implementation using break/span
-- NOTE: note that (pre,post) is essentially destructuring
word2PigAlt :: String -> String
word2PigAlt w
  | startsVowel w = post ++ "yay"
  | otherwise = post ++ pre ++ "ay" where
      (pre,post) = break isVowel w

toPigAlt :: String -> String
toPigAlt = unwords . map word2PigAlt . words

-- Is Prime
isPrime :: Int -> Bool
isPrime n
  | n < 1 = False
  | n == 1 = True
  | sum [m | m <- [2..(n-1)], n `mod` m == 0] == 0 = True
  | otherwise = False

-- reverseString
_reverseString :: String -> String
_reverseString = reverse

-- Reverse String, actual implementation
reverseString :: String -> String
reverseString (c:cs)
  | null cs = [c]
  | otherwise = reverseString cs ++ [c]


-- Range write a function that returns a range. lel
returnRange :: Int -> Int -> [Int]
returnRange a b = [a..b]
