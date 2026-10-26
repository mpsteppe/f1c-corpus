// HUDFlagRendererSecondary: Same flag bytes as main (blue=65) but renders via UITextRenderWithScale (text overlay). Duplicate check pattern suggests HUD location difference.
// positive sp value has been detected, the output may be wrong!
char __userpurge HUDFlagRendererSecondary@<al>(char a1@<al>, int a2@<esi>, int a3, int a4)
{
  char result; // al
  _BYTE v5[8]; // [esp-8h] [ebp-8h] BYREF

  if ( a1 )
  {
    v5[0] = 62;
    a2 = 1;
  }
  if ( VehicleFlagCheck() )
    v5[a2++] = 65;
  if ( PitStateFlagCheck() )
    v5[a2++] = 102;
  result = DisqualificationCheck();
  if ( result )
    v5[a2++] = 63;
  if ( dword_7C56A8 == 8 )
    v5[a2++] = 66;
  if ( a2 > 0 )
  {
    v5[a2] = 0;
    return UITextRenderWithScale((int)v5, a3 + 5, a4, 0xFFFFFF, 0, 3, 2.0, 2.0);
  }
  return result;
}

