int __thiscall SetupValueFormatDispatcher(int this, int a2, int a3)
{
  int result; // eax
  double v4; // [esp+14h] [ebp-10h]
  double v5; // [esp+1Ch] [ebp-8h]

  result = ((a3 + 11 * a2) << 6) + this + 176;
  switch ( a3 )
  {
    case 0:
      return StringFormatWithBufferOverflowCheck(
               (_BYTE *)(result + 30),
               (int)"%.1f %s",
               ((double)*(int *)(result + 20) * *(double *)(result + 8) + *(double *)result) * 57.29577951308232,
               (const char *)(this + 40));
    case 1:
      v5 = (double)*(int *)(result + 20) * *(double *)(result + 8) + *(double *)result;
      if ( *(_DWORD *)(this + 4) )
        return StringFormatWithBufferOverflowCheck(
                 (_BYTE *)(((a3 + 11 * a2) << 6) + this + 206),
                 (int)"%.1f %s",
                 v5 * 0.1450377377387031,
                 (const char *)(this + 8));
      else
        return StringFormatWithBufferOverflowCheck(
                 (_BYTE *)(((a3 + 11 * a2) << 6) + this + 206),
                 (int)"%d %s",
                 (int)v5,
                 (const char *)(this + 8));
    case 2:
      v4 = 0.0;
      if ( a2 == 1 )
      {
        HIDWORD(v4) = -1075838976;
      }
      else
      {
        if ( a2 != 2 )
          return SetupValueFormatWithOffset(this, result, v4);
        HIDWORD(v4) = 1071644672;
      }
      LODWORD(v4) = 0;
      return SetupValueFormatWithOffset(this, result, v4);
    case 3:
    case 9:
      return SetupValueFormatWithOffset(this, result, 0.0);
    case 4:
      return SetupValueFormatDS(this, result);
    case 5:
    case 6:
    case 7:
    case 8:
      return SetupValueFormat1fS(this, result);
    case 10:
      return StringFormatWithBufferOverflowCheck((_BYTE *)(result + 30), (int)"%d", *(_DWORD *)(result + 20) + 1);
    default:
      return result;
  }
}
