char *__thiscall sub_57D400(void *this)
{
  int Error; // eax
  char *result; // eax

  Error = (int)this;
  if ( this == (void *)-1 )
    Error = WSAGetLastError();
  switch ( Error )
  {
    case 10004:
      result = aABlockingWindo_0;
      break;
    case 10009:
      result = aForWindowsCeAf;
      break;
    case 10013:
      result = aTheRequestedAd;
      break;
    case 10014:
      result = aTheNameOrTheNa;
      break;
    case 10022:
      result = aErrorCodeWsaei;
      break;
    case 10024:
      result = aNoMoreSocketDe;
      break;
    case 10035:
      result = aTheSocketIsMar;
      break;
    case 10036:
      result = aABlockingWindo;
      break;
    case 10037:
      result = aANonblockingCo;
      break;
    case 10038:
      result = aTheDescriptorI;
      break;
    case 10039:
      result = aADestinationAd;
      break;
    case 10040:
      result = aTheSocketIsMes;
      break;
    case 10041:
      result = aTheSpecifiedPr_0;
      break;
    case 10043:
      result = aTheSpecifiedPr;
      break;
    case 10044:
      result = aTheSpecifiedSo;
      break;
    case 10045:
      result = aMsgOobWasSpeci;
      break;
    case 10047:
      result = aTheSpecifiedAd;
      break;
    case 10048:
      result = aTheSocketSLoca;
      break;
    case 10049:
      result = aTheRemoteAddre;
      break;
    case 10050:
      result = aTheNetworkSubs;
      break;
    case 10051:
      result = aTheNetworkCann;
      break;
    case 10052:
      result = aTheConnectionH;
      break;
    case 10053:
      result = aTheVirtualCirc;
      break;
    case 10054:
      result = aTheVirtualCirc_0;
      break;
    case 10055:
      result = aNoBufferSpaceI;
      break;
    case 10057:
      result = aTheSocketIsNot;
      break;
    case 10058:
      result = aTheSocketHasBe;
      break;
    case 10060:
      result = aTheConnectionH_0;
      break;
    case 10061:
      result = aTheAttemptToCo;
      break;
    case 10065:
      result = aTheRemoteHostC;
      break;
    case 10093:
      result = aASuccessfulWsa;
      break;
    default:
      result = aWsagetlasterro;
      break;
  }
  return result;
}

