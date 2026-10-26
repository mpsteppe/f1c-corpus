void __thiscall sub_500B60(float *this)
{
  int v2; // eax
  int v3; // ebp
  _DWORD *v4; // ebx
  int v5; // esi
  float v6; // [esp+4h] [ebp-1Ch]
  int v7; // [esp+18h] [ebp-8h]

  if ( *(_DWORD *)dword_B640C8 == 6 )
  {
    if ( *(_DWORD *)(*(_DWORD *)this + 19288) )
    {
      v2 = *(_DWORD *)(*(_DWORD *)this + 19284) + 1;
      v3 = 0;
      if ( *((int *)this + 169) > 0 )
      {
        v4 = this + 170;
        do
        {
          if ( *v4 == v2 && *((_DWORD *)this + 188) != 1 )
          {
            this[190] = dbl_FB1D18;
            v5 = off_9034A4;
            if ( dword_82F4A0 < 1023 )
            {
              ++dword_82F4A0;
              off_9034A4 += 848;
            }
            v6 = dbl_FB1D18;
            sub_51B2A0(6, 5, 1, *((_DWORD *)this + 1), LODWORD(v6), 0);
            *(_BYTE *)(v5 + 8) = 1;
            sub_4FD580();
            v2 = v7;
          }
          ++v3;
          v4 += 2;
        }
        while ( v3 < *((_DWORD *)this + 169) );
      }
    }
  }
}
