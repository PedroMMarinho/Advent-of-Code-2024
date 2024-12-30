import System.IO
import Debug.Trace

checkSafety :: String -> Int
checkSafety line = res
                where listN =  map read (words line) :: [Int]
                      safetyListLessThan = [ let num = (listN !! i - listN !! (i + 1)) 
                                                 in (num > 0 && num <= 3)| i<-[0..length(listN) - 2]]
                      safetyListGreaterThan = [ let num = (listN !! i - listN !! (i + 1)) 
                                                 in (num < 0 && num >= -3)| i<-[0..length(listN) - 2]]                           
                      res = if all (==True) safetyListLessThan || all (==True) safetyListGreaterThan then 1 else 0
                      
parseInput :: FilePath -> IO (Int)
parseInput fileName = do 
    fileContent <- readFile fileName
    let fileLines = lines fileContent
        res = map checkSafety fileLines
    return (sum res)


day2 :: IO ()
day2 = do
    safeReports <- parseInput "input.txt" 
    putStrLn (show safeReports)