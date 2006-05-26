/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2003 RiskMap srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/reference/license.html>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file nullcalendar.hpp
    \brief Calendar for reproducing theoretical calculations
*/

#ifndef quantlib_null_calendar_hpp
#define quantlib_null_calendar_hpp

#include <ql/calendar.hpp>

namespace QuantLib {

    //! %Calendar for reproducing theoretical calculations.
    /*! This calendar has no holidays. It ensures that dates at
        whole-month distances have the same day of month.

        \ingroup calendars
    */
    class NullCalendar : public Calendar {
      private:
        class Impl : public Calendar::Impl {
          public:
            std::string name() const { return "Null"; }
            bool isWeekend(Weekday) const { return false; }
            bool isBusinessDay(const Date&) const { return true; }
        };
      public:
        NullCalendar()
        : Calendar(boost::shared_ptr<Calendar::Impl>(
                                                 new NullCalendar::Impl)) {}
    };

}


#endif
