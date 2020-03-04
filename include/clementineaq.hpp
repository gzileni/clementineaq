#include <eosio/eosio.hpp>
#include <eosio/time.hpp>

using namespace std;
using namespace eosio;

CONTRACT clementineaq : public contract {
  public:
    using contract::contract;

    ACTION send(name from,
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
                uint8_t Verification);
    ACTION clear(name from);
    
  private:

    TABLE airquality {
      name                  from;
      string                Countrycode;
      string 	              Namespace;	
      string                AirQualityNetwork;	
      string                AirQualityStation;
      string 	              AirQualityStationEoICode;
      string	              SamplingPoint;	
      string                SamplingProcess;
      string	              Sample;
      string	              AirPollutant;	
      string                AirPollutantCode;	
      string                AveragingTime;
      double	              Concentration;	
      string                UnitOfMeasurement;	
      time_point            DatetimeBegin;	
      time_point            DatetimeEnd;
      uint8_t	              Validity;	
      uint8_t               Verification;
      time_point_sec        created_at;

      uint64_t primary_key() const { 
        return  from.value; 
      }
      
    };

    typedef multi_index<
      "airquality"_n, 
      airquality>
      airquality_t;
};