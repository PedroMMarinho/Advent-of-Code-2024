import System.IO
import Data.List

parseInput :: FilePath -> IO ([Int], [Int])
parseInput fileName = do 
    fileContent <- readFile fileName
    let fileLines = lines fileContent
        (list1, list2) = foldl readLine ([],[]) fileLines
    return (list1,list2)
    

readLine :: ([Int],[Int]) -> String -> ([Int],[Int])
readLine (l1,l2) line = (insert num1 l1, insert num2 l2)
                where [num1,num2] = map read (words line)

day1 :: IO ()
day1 = do
    (list1,list2) <- parseInput "input.txt"
    let res = foldl (\acc (x,y) -> abs(x - y) + acc) 0 (zip list1 list2)
    putStrLn (show res)
    