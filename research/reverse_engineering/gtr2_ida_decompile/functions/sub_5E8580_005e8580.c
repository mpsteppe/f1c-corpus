void __thiscall sub_5E8580(float *this, int a2, _DWORD *a3)
{
  unsigned int v3; // ebx
  unsigned __int64 v4; // rax
  double v5; // st7

  if ( a3 )
  {
    switch ( a2 )
    {
      case 1:
        v3 = ((unsigned int)(unsigned __int64)(this[22] * -255.0)
            + ((unsigned int)(unsigned __int64)(this[25] * -255.0) << 8)) << 8;
        v4 = (unsigned __int64)(this[23] * -255.0);
        v5 = this[24];
        goto LABEL_7;
      case 2:
        v3 = ((unsigned int)(unsigned __int64)(this[18] * -255.0)
            + ((unsigned int)(unsigned __int64)(this[21] * -255.0) << 8)) << 8;
        v4 = (unsigned __int64)(this[19] * -255.0);
        v5 = this[20];
        goto LABEL_7;
      case 3:
        v3 = ((unsigned int)(unsigned __int64)(this[26] * -255.0)
            + ((unsigned int)(unsigned __int64)(this[29] * -255.0) << 8)) << 8;
        v4 = (unsigned __int64)(this[27] * -255.0);
        v5 = this[28];
        goto LABEL_7;
      case 4:
        v3 = ((unsigned int)(unsigned __int64)(this[30] * -255.0)
            + ((unsigned int)(unsigned __int64)(this[33] * -255.0) << 8)) << 8;
        v4 = (unsigned __int64)(this[31] * -255.0);
        v5 = this[32];
LABEL_7:
        *a3 = (unsigned __int64)(v5 * 255.0) - (((_DWORD)v4 + v3) << 8);
        break;
      default:
        return;
    }
  }
}
