# Course 8 (Algorithms – Level 4): Problem Solutions

Matched against the course PDF (65 problem numbers) and the solution files in the local folder.

## Status legend

| Status | Meaning |
|---|---|
| **Done** | File content was read and matches the problem |
| **Done (by name)** | Matched from function names only; content not read yet |
| **Partial** | The logic exists inside another file (as a function), but there is no standalone program |
| **Missing** | No solution found |

## Summary

| Status | Problems |
|---|---|
| Done | 43 |
| Done (by name) | 16 |
| Partial | 4 (2, 6, 56, 57) |
| Missing | 2 (19, 65) |

## Map

The "Folder" column shows where each file lives in this repo. Files keep their original names, so use this table to find which problem each file solves.

| # | Problem | File | Status | Notes | Folder |
|---|---|---|---|---|---|
| 1 | Number To Text | `p1.cpp` | Done (by name) | `NumberToText()` | `00-recursion` |
| 2 | Leap Year | `p2.cpp` | Partial | File holds the one-line ternary version (the form of Problem 3); the original if/else version was likely overwritten | `01-leap-year-and-time-units` |
| 3 | Leap Year (One Line Of Code) | `p2.cpp` | Done | Ternary one-liner | `01-leap-year-and-time-units` |
| 4 | Number of Days – Hours – Minutes – Seconds in a Year | `ps4.cpp` | Done | | `01-leap-year-and-time-units` |
| 5 | Number of Days – Hours – Minutes – Seconds in a Month | `ps5.cpp` | Done | | `01-leap-year-and-time-units` |
| 6 | Number of Days in a Month Short Logic | `ps5.cpp` | Partial | `DaysBerMonth()` holds the logic; no standalone program | `01-leap-year-and-time-units` |
| 7 | Day Name | `ps7.cpp` | Done (by name) | `DayOfWeak()`; same file as 8 | `02-calendar` |
| 8 | Month Calendar | `ps7.cpp` | Done (by name) | `Calender()` | `02-calendar` |
| 9 | Year Calendar | `ps9.cpp` | Done (by name) | `YearCalender()` | `02-calendar` |
| 10 | Days from the beginning of Year | `ps10.cpp` | Done (by name) | `NumberOfDaysFromBeggingOfYear()` | `03-date-basics` |
| 11 | Date from Day Order In a Year | `ps11.cpp` | Done (by name) | `daytodate()` | `03-date-basics` |
| 12 | Add Days to Date | `ps12.cpp` | Done (by name) | `daytodate()` with a date and days | `03-date-basics` |
| 13 | Date1 Less Than Date2 | `ps13to15.cpp` | Done | One `DateCompDate()` covers 13 and 14 | `03-date-basics` |
| 14 | Date1 Equals To Date2 | `ps13to15.cpp` | Done | | `03-date-basics` |
| 15 | Last Day, Last Month | `ps15.cpp` | Done | File name `ps13to15` is misleading: 15 lives in `ps15.cpp` | `03-date-basics` |
| 16 | Increase Date By One Day | `ps16.cpp` | Done | Function is named `MinusOneDay` but it increments | `03-date-basics` |
| 17 | Diff In Days | `ps17.cpp` | Done (by name) | `diffdays()` | `03-date-basics` |
| 18 | Your Age In Days | `ps17hadhod.cpp` | Done | User date vs `GetSystemDate()` | `03-date-basics` |
| 19 | Diff In Days (Negative Days) | none | Missing | `DiffInDays` in `ps17hadhod.cpp` only prints a warning when Date1 > Date2 | `03-date-basics` |
| 20–32 | Increase Date Problems | `ps20to32.cpp` | Done (mostly) | Has: day, 10 days, week, 10 weeks, month, 10 months, year, 10 years, 10 decades, century, millennium. Not found: one decade, and the separate slow-loop vs faster years variants. Functions are named `Minusing*` but they add | `04-increase-date` |
| 33–46 | Decrease Date Problems | `ps33tp46.cpp` | Done (mostly) | Real decrement logic. Same set as above (with 5 months). Not found: one decade and the slow-loop year variants | `05-decrease-date` |
| 47–53 | More Date Problems | `ps47to53.cpp` | Done (mostly) | End of week, weekend (Fri/Sat), business day, days until end of week / month / year; all written inside `main` instead of separate functions. The PDF's seventh item still needs to be compared | `06-weekdays-and-vacation` |
| 54 | Calculate Vacation Days | `ps54.cpp` | Done (by name) | Has `isendweek()`, `DayOfWeak()`, `AddOneDay()` | `06-weekdays-and-vacation` |
| 55 | Calculate Vacation Return Date | `ps55.cpp` | Done (by name) | Same helper functions as 54 | `06-weekdays-and-vacation` |
| 56 | Is Date1 After Date2 | `ps60.cpp` (function only) | Partial | `isDate1afterDate2()` exists inside `ps60.cpp`; no standalone program | `07-compare-and-periods` |
| 57 | Compare Date Function | `ps56.cpp` (function only) | Partial | `CompareDate()` and its enum exist inside `ps56.cpp`; no standalone program | `07-compare-and-periods` |
| 58 | Is Overlap Periods | `ps56.cpp` | Done | File is named `ps56` but its `main` is the overlap problem (58) | `07-compare-and-periods` |
| 59 | Period Length In Days | `ps59.cpp` | Done (by name) | `diffdays(start, end)` | `07-compare-and-periods` |
| 60 | Is Date Within Period | `ps60.cpp` | Done (by name) | `isDateInPeriod()` | `07-compare-and-periods` |
| 61 | Count Overlap Days | `ps61.cpp` | Done (by name) | Has `findoverlap()`; need to read how the days are counted | `07-compare-and-periods` |
| 62 | Validate Date | `ps62.cpp` | Done (by name) | `IsValidate()` | `08-validate-and-format` |
| 63–64 | Read / Print Date String | `ps63.cpp` | Done (by name) | `GetStringDate()`, `splitstring()`; not checked whether the print part (64) is included | `08-validate-and-format` |
| 65 | Format Date | none | Missing | No format function found in any file | `08-validate-and-format` |

## Files that are not Course 8 problems

| File | What it is |
|---|---|
| `UsersClientsBank.cpp` | Users / clients bank management project (770 lines); belongs in its own folder |

## Open items for the cleanup stage

- Some file names are misleading (`ps13to15.cpp` holds only 13 and 14, `ps56.cpp` holds 58, `ps17hadhod.cpp` holds 18). They keep their original names; this table is the reference.
- `Minusing*` functions in `ps20to32.cpp` add instead of subtract, and several return `stDate` without a `return`.
- Read the 14 "by name" files to confirm each one.
