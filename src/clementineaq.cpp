#include <clementineaq.hpp>
#include <eosio/eosio.hpp>
#include <eosio/time.hpp>
#include <eosio/system.hpp>
#include <eosio/crypto.hpp>

using namespace std;
using namespace eosio;

ACTION clementineaq::send(name from,
                          string Countrycode,
                          string Namespace,	
                          string AirQualityNetwork,	
                          string AirQualityStation,
                          string AirQualityStationEoICode,
                          string SamplingPoint,	
                          string SamplingProcess,
                          string Sample,
                          string AirPollutant,	
                          string AirPollutantCode,	
                          string AveragingTime,
                          double Concentration,	
                          string UnitOfMeasurement,	
                          time_point DatetimeBegin,	
                          time_point DatetimeEnd,
                          uint8_t	Validity,
                          uint8_t Verification) {

  require_auth(from);
  
  check(Concentration == 0, "Concentration value should be greater 0!");
  check(Validity <= 0, "Validity flag shouldn't be greater 1!");
  check(Verification > 1, "Verification flag shouldn't be equals 1!");

  // Init the _message table
  airquality_t _aq(from, from.value);

  _aq.emplace(from, [&](auto& s) {
    s.from = from;
    s.Countrycode = Countrycode;
    s.Namespace = Namespace; 	
    s.AirQualityNetwork = AirQualityNetwork; 	
    s.AirQualityStation = AirQualityStation;
    s.AirQualityStationEoICode = AirQualityStationEoICode;
    s.SamplingPoint = SamplingPoint;
    s.SamplingProcess = SamplingProcess;
    s.Sample = Sample;
    s.AirPollutant =AirPollutant;
    s.AirPollutantCode =AirPollutantCode;
    s.AveragingTime = AveragingTime;
    s.Concentration =	Concentration;
    s.UnitOfMeasurement = UnitOfMeasurement;
    s.DatetimeBegin = DatetimeBegin;
    s.DatetimeEnd =  DatetimeEnd; 
    s.Validity = Validity; 
    s.Verification = Verification;
  });

}

ACTION clementineaq::clear(name from) {
  
  require_auth(from);

  airquality_t _aq(from, from.value);

  // Delete all records in _messages table
  auto s_itr = _aq.begin();
  while (s_itr != _aq.end()) {
    s_itr = _aq.erase(s_itr);
  }
}

EOSIO_DISPATCH(clementineaq, (send)(clear))
