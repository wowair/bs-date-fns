type timeUnit = | Second | Minute | Hour | Day | Month | Year;
type partialMethod = | Floor | Ceil | Round;

let timeUnitToString = fun
  | Second => "s"
  | Minute => "m"
  | Hour => "h"
  | Day => "d"
  | Month => "M"
  | Year => "Y";
let partialMethodToString = fun
  | Floor => "floor"
  | Ceil => "ceil"
  | Round => "round";

[@bs.module "date-fns"] external closestIndexTo : (Js.Date.t, array(Js.Date.t)) => int = "closestIndexTo";
[@bs.module "date-fns"] external closestTo : (Js.Date.t, array(Js.Date.t)) => Js.Date.t = "closestTo";
[@bs.module "date-fns"] external compareAsc : (Js.Date.t, Js.Date.t) => int = "compareAsc";
[@bs.module "date-fns"] external compareDesc : (Js.Date.t, Js.Date.t) => int = "compareDesc";
type formatDistanceOptions = {.
  "includeSeconds": Js.Nullable.t(bool),
  "addSuffix": Js.Nullable.t(bool),
};
[@bs.module "date-fns"] external internal_formatDistance : (Js.Date.t, Js.Date.t, formatDistanceOptions) => string = "formatDistance";
let formatDistance = (date, dateToCompare, ~includeSeconds=?, ~addSuffix=?, ()) =>
  internal_formatDistance(date, dateToCompare, Js.Nullable.{
    "includeSeconds": includeSeconds |> fromOption,
    "addSuffix": addSuffix |> fromOption
  });
type formatDistanceStrictOptions = {.
  "addSuffix": Js.Nullable.t(bool),
  "unit": Js.Nullable.t(string),
  "partialMethod": Js.Nullable.t(string)
};
[@bs.module "date-fns"] external internal_formatDistanceStrict : (Js.Date.t, Js.Date.t, formatDistanceStrictOptions) => string = "formatDistanceStrict";
let formatDistanceStrict = (dateToCompare, date, ~addSuffix=?, ~unit=?, ~partialMethod=?, ()) =>
  internal_formatDistanceStrict(date, dateToCompare, Js.Nullable.{
    "addSuffix": addSuffix |> fromOption,
    "unit": unit
      |> Js.Option.map([@bs] unit => timeUnitToString(unit))
      |> fromOption,
    "partialMethod": partialMethod
      |> Js.Option.map([@bs] partialMethod => partialMethodToString(partialMethod))
      |> fromOption
  });

[@bs.module "date-fns"] external format : (Js.Date.t, string) => string = "format";
[@bs.module "date-fns"] external isAfter : (Js.Date.t, Js.Date.t) => bool = "isAfter";
[@bs.module "date-fns"] external isBefore : (Js.Date.t, Js.Date.t) => bool = "isBefore";
[@bs.module "date-fns"] external isEqual : (Js.Date.t, Js.Date.t) => bool = "isEqual";
[@bs.module "date-fns"] external isFuture : Js.Date.t => bool = "isFuture";
[@bs.module "date-fns"] external isPast : Js.Date.t => bool = "isPast";
[@bs.module "date-fns"] external isValid : Js.Date.t => bool = "isValid";
[@bs.module "date-fns"] [@bs.splice] external max : array(Js.Date.t) => Js.Date.t = "max";
[@bs.module "date-fns"] [@bs.splice] external min : array(Js.Date.t) => Js.Date.t = "min";
type parseOptions = {.
  "locale": Js.Nullable.t(string),
  "weekStartsOn": Js.Nullable.t(int),
  "firstWeekContainsDate": Js.Nullable.t(int),
  "awareOfUnicodeTokens": Js.Nullable.t(bool),
};
[@bs.module "date-fns"] external internal_parse : (string, string, Js.Date.t, parseOptions) => Js.Date.t = "parse";
let parse = (dateString, formatString, baseDate, ~locale=?, ~weekStartsOn=?, ~firstWeekContainsDate=?, ~awareOfUnicodeTokens=?, ()) =>
internal_parse(dateString, formatString, baseDate, Js.Nullable.{
  "locale": locale |> fromOption,
  "weekStartsOn": weekStartsOn |> fromOption,
  "firstWeekContainsDate": firstWeekContainsDate |> fromOption,
  "awareOfUnicodeTokens": awareOfUnicodeTokens |> fromOption,
});

[@bs.module "date-fns"] external internal_floatToDate : float => Js.Date.t = "toDate";
let parseFloat = (float) => internal_floatToDate(float);
[@bs.module "date-fns"] external internal_stringToDate : Js.Date.t => Js.Date.t = "toDate";
let parseString = (string) => internal_stringToDate(string);
[@bs.module "date-fns"] external areRangesOverlapping : (Js.Date.t, Js.Date.t, Js.Date.t, Js.Date.t) => bool = "areRangesOverlapping";
[@bs.module "date-fns"] external getOverlappingDaysInRanges : (Js.Date.t, Js.Date.t, Js.Date.t, Js.Date.t) => float = "getOverlappingDaysInRanges";
type isWithinIntervalDates = {.
  "start": Js.Date.t,
  "end": Js.Date.t,
};
[@bs.module "date-fns"] external internal_isWithinInterval : (Js.Date.t, isWithinIntervalDates) => bool = "isWithinInterval";
let isWithinInterval = (date, startDate, endDate) => internal_isWithinInterval(date, {"start": startDate, "end": endDate});

[@bs.module "date-fns"] external getTime : Js.Date.t => float = "getTime";
[@bs.module "date-fns"] external getMilliseconds : (Js.Date.t) => float = "getMilliseconds";
[@bs.module "date-fns"] external getSeconds : (Js.Date.t) => float = "getSeconds";
[@bs.module "date-fns"] external getMinutes : (Js.Date.t) => float = "getMinutes";
[@bs.module "date-fns"] external getHours : (Js.Date.t) => float = "getHours";
[@bs.module "date-fns"] external getDate : (Js.Date.t) => float = "getDate";
[@bs.module "date-fns"] external getDayOfYear : (Js.Date.t) => float = "getDayOfYear";
[@bs.module "date-fns"] external getDay : (Js.Date.t) => float = "getDay";
[@bs.module "date-fns"] external getISODay : (Js.Date.t) => float = "getISODay";
[@bs.module "date-fns"] external getISOWeek : (Js.Date.t) => float = "getISOWeek";
[@bs.module "date-fns"] external getDaysInMonth : (Js.Date.t) => float = "getDaysInMonth";
[@bs.module "date-fns"] external getMonth : (Js.Date.t) => float = "getMonth";
[@bs.module "date-fns"] external getQuarter : (Js.Date.t) => float = "getQuarter";
[@bs.module "date-fns"] external getDaysInYear : (Js.Date.t) => float = "getDaysInYear";
[@bs.module "date-fns"] external getYear : (Js.Date.t) => float = "getYear";
[@bs.module "date-fns"] external getISOWeeksInYear : (Js.Date.t) => float = "getISOWeeksInYear";
[@bs.module "date-fns"] external getISOYear : (Js.Date.t) => float = "getISOYear";

[@bs.module "date-fns"] external setMilliseconds : (Js.Date.t, float) => Js.Date.t = "setMilliseconds";
[@bs.module "date-fns"] external setSeconds : (Js.Date.t, float) => Js.Date.t = "setSeconds";
[@bs.module "date-fns"] external setMinutes : (Js.Date.t, float) => Js.Date.t = "setMinutes";
[@bs.module "date-fns"] external setHours : (Js.Date.t, float) => Js.Date.t = "setHours";
[@bs.module "date-fns"] external setDate : (Js.Date.t, float) => Js.Date.t = "setDate";
[@bs.module "date-fns"] external setDayOfYear : (Js.Date.t, float) => Js.Date.t = "setDayOfYear";
[@bs.module "date-fns"] external setDay : (Js.Date.t, float) => Js.Date.t = "setDay";
[@bs.module "date-fns"] external setISODay : (Js.Date.t, float) => Js.Date.t = "setISODay";
[@bs.module "date-fns"] external setISOWeek : (Js.Date.t, float) => Js.Date.t = "setISOWeek";
[@bs.module "date-fns"] external setMonth : (Js.Date.t, float) => Js.Date.t = "setMonth";
[@bs.module "date-fns"] external setQuarter : (Js.Date.t, float) => Js.Date.t = "setQuarter";
[@bs.module "date-fns"] external setYear : (Js.Date.t, float) => Js.Date.t = "setYear";
[@bs.module "date-fns"] external setISOWeekYear : (Js.Date.t, float) => Js.Date.t = "setISOWeekYear";

[@bs.module "date-fns"] external subMilliseconds : (Js.Date.t, float) => Js.Date.t = "subMilliseconds";
[@bs.module "date-fns"] external subSeconds : (Js.Date.t, float) => Js.Date.t = "subSeconds";
[@bs.module "date-fns"] external subMinutes : (Js.Date.t, float) => Js.Date.t = "subMinutes";
[@bs.module "date-fns"] external subHours : (Js.Date.t, float) => Js.Date.t = "subHours";
[@bs.module "date-fns"] external subDays : (Js.Date.t, float) => Js.Date.t = "subDays";
[@bs.module "date-fns"] external subWeeks : (Js.Date.t, float) => Js.Date.t = "subWeeks";
[@bs.module "date-fns"] external subMonths : (Js.Date.t, float) => Js.Date.t = "subMonths";
[@bs.module "date-fns"] external subQuarters : (Js.Date.t, float) => Js.Date.t = "subQuarters";
[@bs.module "date-fns"] external subYears : (Js.Date.t, float) => Js.Date.t = "subYears";
[@bs.module "date-fns"] external subISOWeekYears : (Js.Date.t, float) => Js.Date.t = "subISOWeekYears";

[@bs.module "date-fns"] external addMilliseconds : (Js.Date.t, float) => Js.Date.t = "addMilliseconds";
[@bs.module "date-fns"] external addSeconds : (Js.Date.t, float) => Js.Date.t = "addSeconds";
[@bs.module "date-fns"] external addMinutes : (Js.Date.t, float) => Js.Date.t = "addMinutes";
[@bs.module "date-fns"] external addHours : (Js.Date.t, float) => Js.Date.t = "addHours";
[@bs.module "date-fns"] external addDays : (Js.Date.t, float) => Js.Date.t = "addDays";
[@bs.module "date-fns"] external addWeeks : (Js.Date.t, float) => Js.Date.t = "addWeeks";
[@bs.module "date-fns"] external addMonths : (Js.Date.t, float) => Js.Date.t = "addMonths";
[@bs.module "date-fns"] external addQuarters : (Js.Date.t, float) => Js.Date.t = "addQuarters";
[@bs.module "date-fns"] external addYears : (Js.Date.t, float) => Js.Date.t = "addYears";
[@bs.module "date-fns"] external addISOWeekYears : (Js.Date.t, float) => Js.Date.t = "addISOWeekYears";

[@bs.module "date-fns"] external isSameSecond : (Js.Date.t, Js.Date.t) => bool = "isSameSecond";
[@bs.module "date-fns"] external isSameMinute : (Js.Date.t, Js.Date.t) => bool = "isSameMinute";
[@bs.module "date-fns"] external isSameHour : (Js.Date.t, Js.Date.t) => bool = "isSameHour";
[@bs.module "date-fns"] external isSameDay : (Js.Date.t, Js.Date.t) => bool = "isSameDay";
[@bs.module "date-fns"] external isSameWeek : (Js.Date.t, Js.Date.t) => bool = "isSameWeek";
[@bs.module "date-fns"] external isSameISOWeek : (Js.Date.t, Js.Date.t) => bool = "isSameISOWeek";
[@bs.module "date-fns"] external isSameMonth : (Js.Date.t, Js.Date.t) => bool = "isSameMonth";
[@bs.module "date-fns"] external isSameQuarter : (Js.Date.t, Js.Date.t) => bool = "isSameQuarter";
[@bs.module "date-fns"] external isSameYear : (Js.Date.t, Js.Date.t) => bool = "isSameYear";
[@bs.module "date-fns"] external isSameISOYear : (Js.Date.t, Js.Date.t) => bool = "isSameISOYear";

[@bs.module "date-fns"] external isMonday : Js.Date.t => bool = "isMonday";
[@bs.module "date-fns"] external isTuesday : Js.Date.t => bool = "isTuesday";
[@bs.module "date-fns"] external isWednesday : Js.Date.t => bool = "isWednesday";
[@bs.module "date-fns"] external isThursday : Js.Date.t => bool = "isThursday";
[@bs.module "date-fns"] external isFriday : Js.Date.t => bool = "isFriday";
[@bs.module "date-fns"] external isSaturday : Js.Date.t => bool = "isSaturday";
[@bs.module "date-fns"] external isSunday : Js.Date.t => bool = "isSunday";
[@bs.module "date-fns"] external isWeekend : Js.Date.t => bool = "isWeekend";

[@bs.module "date-fns"] external differenceInMilliseconds : (Js.Date.t, Js.Date.t) => float = "differenceInMilliseconds";
[@bs.module "date-fns"] external differenceInSeconds : (Js.Date.t, Js.Date.t) => float = "differenceInSeconds";
[@bs.module "date-fns"] external differenceInMinutes : (Js.Date.t, Js.Date.t) => float = "differenceInMinutes";
[@bs.module "date-fns"] external differenceInHours : (Js.Date.t, Js.Date.t) => float = "differenceInHours";
[@bs.module "date-fns"] external differenceInCalendarDays : (Js.Date.t, Js.Date.t) => float = "differenceInCalendarDays";
[@bs.module "date-fns"] external differenceInDays : (Js.Date.t, Js.Date.t) => float = "differenceInDays";
[@bs.module "date-fns"] external differenceInCalendarWeeks : (Js.Date.t, Js.Date.t) => float = "differenceInCalendarWeeks";
[@bs.module "date-fns"] external differenceInWeeks : (Js.Date.t, Js.Date.t) => float = "differenceInWeeks";
[@bs.module "date-fns"] external differenceInCalendarISOWeeks : (Js.Date.t, Js.Date.t) => float = "differenceInCalendarISOWeeks";
[@bs.module "date-fns"] external differenceInCalendarMonths : (Js.Date.t, Js.Date.t) => float = "differenceInCalendarMonths";
[@bs.module "date-fns"] external differenceInMonths : (Js.Date.t, Js.Date.t) => float = "differenceInMonths";
[@bs.module "date-fns"] external differenceInCalendarQuarters : (Js.Date.t, Js.Date.t) => float = "differenceInCalendarQuarters";
[@bs.module "date-fns"] external differenceInQuarters : (Js.Date.t, Js.Date.t) => float = "differenceInQuarters";
[@bs.module "date-fns"] external differenceInYears : (Js.Date.t, Js.Date.t) => float = "differenceInYears";
[@bs.module "date-fns"] external differenceInISOYears : (Js.Date.t, Js.Date.t) => float = "differenceInISOYears";
[@bs.module "date-fns"] external differenceInCalendarYears : (Js.Date.t, Js.Date.t) => float = "differenceInCalendarYears";
[@bs.module "date-fns"] external differenceInCalendarISOYears : (Js.Date.t, Js.Date.t) => float = "differenceInCalendarISOYears";

[@bs.module "date-fns"] external startOfSecond : Js.Date.t => Js.Date.t = "startOfSecond";
[@bs.module "date-fns"] external endOfSecond : Js.Date.t => Js.Date.t = "endOfSecond";
[@bs.module "date-fns"] external startOfMinute : Js.Date.t => Js.Date.t = "startOfMinute";
[@bs.module "date-fns"] external endOfMinute : Js.Date.t => Js.Date.t = "endOfMinute";
[@bs.module "date-fns"] external startOfHour : Js.Date.t => Js.Date.t = "startOfHour";
[@bs.module "date-fns"] external endOfHour : Js.Date.t => Js.Date.t = "endOfHour";
[@bs.module "date-fns"] external startOfDay : Js.Date.t => Js.Date.t = "startOfDay";
[@bs.module "date-fns"] external endOfDay : Js.Date.t => Js.Date.t = "endOfDay";
[@bs.module "date-fns"] external startOfWeek : Js.Date.t => Js.Date.t = "startOfWeek";
[@bs.module "date-fns"] external endOfWeek : Js.Date.t => Js.Date.t = "endOfWeek";
[@bs.module "date-fns"] external startOfISOWeek : Js.Date.t => Js.Date.t = "startOfISOWeek";
[@bs.module "date-fns"] external endOfISOWeek : Js.Date.t => Js.Date.t = "endOfISOWeek";
[@bs.module "date-fns"] external startOfMonth : Js.Date.t => Js.Date.t = "startOfMonth";
[@bs.module "date-fns"] external endOfMonth : Js.Date.t => Js.Date.t = "endOfMonth";
[@bs.module "date-fns"] external startOfQuarter : Js.Date.t => Js.Date.t = "startOfQuarter";
[@bs.module "date-fns"] external endOfQuarter : Js.Date.t => Js.Date.t = "endOfQuarter";
[@bs.module "date-fns"] external startOfYear : Js.Date.t => Js.Date.t = "startOfYear";
[@bs.module "date-fns"] external endOfYear : Js.Date.t => Js.Date.t = "endOfYear";
[@bs.module "date-fns"] external startOfISOYear : Js.Date.t => Js.Date.t = "startOfISOYear";
[@bs.module "date-fns"] external endOfISOYear : Js.Date.t => Js.Date.t = "endOfISOYear";

[@bs.module "date-fns"] external lastDayOfWeek : Js.Date.t => Js.Date.t = "lastDayOfWeek";
[@bs.module "date-fns"] external lastDayOfISOWeek : Js.Date.t => Js.Date.t = "lastDayOfISOWeek";
[@bs.module "date-fns"] external lastDayOfMonth : Js.Date.t => Js.Date.t = "lastDayOfMonth";
[@bs.module "date-fns"] external lastDayOfQuarter : Js.Date.t => Js.Date.t = "lastDayOfQuarter";
[@bs.module "date-fns"] external lastDayOfYear : Js.Date.t => Js.Date.t = "lastDayOfYear";
[@bs.module "date-fns"] external lastDayOfISOYear : Js.Date.t => Js.Date.t = "lastDayOfISOYear";

[@bs.module "date-fns"] external startOfYesterday : unit => Js.Date.t = "startOfYesterday";
[@bs.module "date-fns"] external endOfYesterday : unit => Js.Date.t = "endOfYesterday";
[@bs.module "date-fns"] external startOfToday : unit => Js.Date.t = "startOfToday";
[@bs.module "date-fns"] external endOfToday : unit => Js.Date.t = "endOfToday";
[@bs.module "date-fns"] external startOfTomorrow : unit => Js.Date.t = "startOfTomorrow";
[@bs.module "date-fns"] external endOfTomorrow : unit => Js.Date.t = "endOfTomorrow";

[@bs.module "date-fns"] external isFirstDayOfMonth : Js.Date.t => bool = "isFirstDayOfMonth";
[@bs.module "date-fns"] external isLastDayOfMonth : Js.Date.t => bool = "isLastDayOfMonth";
[@bs.module "date-fns"] external isLeapYear : Js.Date.t => bool = "isLeapYear";

[@bs.module "date-fns"] external eachDay : (Js.Date.t, Js.Date.t) => array(Js.Date.t) = "eachDay";
