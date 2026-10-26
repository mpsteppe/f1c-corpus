void __thiscall sub_47A7D0(void *this)
{
  int i; // edi
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // [esp+0h] [ebp-368h]
  float v7; // [esp+4h] [ebp-364h]

  if ( *(_DWORD *)(*(_DWORD *)this + 113328) )
  {
    if ( *(_DWORD *)dword_B640C8 == 6 && !(unsigned __int8)sub_4735E0(this) )
    {
      *(_BYTE *)(*(_DWORD *)this + 1178) = 0;
      v7 = dbl_FB1D18;
      sub_51B2A0(4, 56, 0, 0, LODWORD(v7), 3);
      sub_4745E0();
    }
    if ( *(_BYTE *)(*(_DWORD *)this + 1184) )
    {
      sub_479D60();
      sub_479E60();
      if ( *(_DWORD *)(*(_DWORD *)this + 113328) == 3 )
      {
        if ( dword_B640C0 != 5
          && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 9167) )
        {
          sub_561210((int)byte_FAE910, "Entering \"SynchronizeWithServer()\"", 1);
        }
        *(_BYTE *)(*(_DWORD *)this + 1179) = 1;
        sub_476C10();
      }
    }
    else
    {
      *(_BYTE *)(*(_DWORD *)this + 1184) = 1;
      for ( i = 0; i < 178920; i += 1704 )
        sub_59A9C0(i + *(_DWORD *)this + 113772);
    }
    *(_BYTE *)(*(_DWORD *)this + 1178) = 0;
    v3 = *(_DWORD *)(*(_DWORD *)this + 113328);
    if ( v3 == 2 || v3 == 1 )
    {
      if ( *(_DWORD *)dword_B640C8 == 6 || *(_DWORD *)dword_B640C8 == 5 || byte_B734E0 && *(_DWORD *)dword_B640C8 == 3 )
        sub_59B770(0);
      else
        sub_59B770(1);
    }
    else
    {
      *(_DWORD *)(*(_DWORD *)this + 16) = 1084227584;
      *(_DWORD *)(*(_DWORD *)this + 2140) = 1008981770;
    }
    v4 = dword_B73294;
    v5 = dword_B73294;
    if ( dword_B73294 <= 4 )
      v5 = 4;
    if ( dword_B732B8 >= v5 )
    {
      if ( dword_B73294 <= 4 )
        v4 = 4;
    }
    else
    {
      v4 = dword_B732B8;
    }
    v6 = 6;
    switch ( v4 )
    {
      case 6:
        v6 = 6;
        break;
      case 8:
        v6 = 8;
        break;
      case 12:
      case 14:
        v6 = 10;
        break;
      case 32:
        v6 = 20;
        break;
      default:
        break;
    }
    *(float *)(*(_DWORD *)this + 4) = 1.0 / (double)v6;
    *(_DWORD *)(*(_DWORD *)this + 2132) = 0;
    *(_DWORD *)(*(_DWORD *)this + 2124) = 0;
    sub_479880(*(_DWORD *)this + 292692, 1);
    nullsub_7((void *)(*(_DWORD *)this + 302748));
  }
}
