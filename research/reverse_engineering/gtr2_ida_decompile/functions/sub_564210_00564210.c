void __usercall sub_564210(int a1@<edi>)
{
  bool v1; // bl
  int v2; // esi
  int v3; // eax
  float v4; // [esp+4h] [ebp-4h]

  v1 = fmod(dbl_FB1D18, 0.75) > 0.30000001;
  if ( !(unsigned __int8)sub_5785A0(dword_91E07C + 16, a1) || !v1 )
  {
    v2 = 0;
    v4 = *((float *)dword_91E07C + 4307) / *((float *)dword_91E07C + 4308);
    do
    {
      if ( v4 > dbl_720E80[v2] )
      {
        v3 = 65280;
        if ( v2 <= 35 || v2 >= 43 )
        {
          if ( v2 <= 42 || v2 >= 48 )
          {
            if ( v2 > 47 )
              v3 = (int)dword_FF0000;
          }
          else
          {
            v3 = 16688384;
          }
        }
        else
        {
          v3 = (int)dword_FFFF00;
        }
        sub_562B70((int)";", *(&dword_720CE0 + 2 * v2), dword_720CE4[2 * v2], v3, 0, 4, 0.5, 0.5);
      }
      ++v2;
    }
    while ( v2 < 52 );
  }
}
