#if !defined(Repro_CertPublicationHandler_hxx)
#define Repro_CertPublicationHandler_hxx

#include "resip/dum/PublicationHandler.hxx"

namespace resip
{
class Security;
class SipMessage;
class SecurityAttributes;
class Data;
class Contents;
}

namespace repro
{

class CertPublicationHandler : public resip::ServerPublicationHandler
{
   public:
      CertPublicationHandler(resip::Security& security);
      virtual void onInitial(resip::ServerPublicationHandle h, 
                             const resip::Data& etag, 
                             const resip::SipMessage& pub, 
                             const resip::Contents* contents,
                             const resip::SecurityAttributes* attrs, 
                             uint32_t expires);
      virtual void onExpired(resip::ServerPublicationHandle h, const resip::Data& etag);
      virtual void onRefresh(resip::ServerPublicationHandle, 
                             const resip::Data& etag, 
                             const resip::SipMessage& pub, 
                             const resip::Contents* contents,
                             const resip::SecurityAttributes* attrs,
                             uint32_t expires);
      virtual void onUpdate(resip::ServerPublicationHandle h, 
                            const resip::Data& etag, 
                            const resip::SipMessage& pub, 
                            const resip::Contents* contents,
                            const resip::SecurityAttributes* attrs,
                            uint32_t expires);
      virtual void onRemoved(resip::ServerPublicationHandle h, const resip::Data& etag, const resip::SipMessage& pub, uint32_t expires);
      
   private:
      void add(resip::ServerPublicationHandle h, const resip::Contents* contents);
      
      resip::Security& mSecurity;
};
 
}

#endif 
