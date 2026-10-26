void __thiscall sub_5FBCC0(char *this, int a2)
{
  _DWORD *v3; // edi
  char v4; // bl
  _DWORD **v5; // eax
  _DWORD *v6; // ecx
  int v7; // eax
  _DWORD **v8; // eax
  float v9; // [esp+0h] [ebp-18h]
  float v10; // [esp+0h] [ebp-18h]
  float v11; // [esp+4h] [ebp-14h]
  float v12; // [esp+10h] [ebp-8h] BYREF
  float v13; // [esp+14h] [ebp-4h] BYREF

  if ( (*this & 2) == 0 )
  {
    v3 = (_DWORD *)a2;
    if ( sub_5DA650(this, a2) )
    {
      if ( (*(_DWORD *)this & 0x2100) != 0 )
      {
        sub_5E4DA0(v3, &v13, &a2, &v12);
        if ( (*(_DWORD *)this & 0x100) != 0 )
        {
          v11 = -v12;
          v9 = 3.1415927 - *(float *)&a2;
          sub_5DB1E0(this, v13, v9, v11);
        }
        else if ( (*(_DWORD *)this & 0x2000) != 0 )
        {
          v10 = 3.1415927 - *(float *)&a2;
          sub_5DB1E0(this, 0.0, v10, 0.0);
        }
      }
      v4 = sub_5DAE90(this, 1, 1);
      if ( sub_5DAF80((float *)this, (int)v3, 0) )
      {
        sub_5FBB60((int)this, (int)v3);
        v5 = (_DWORD **)*((_DWORD *)this + 157);
        *((_DWORD *)this + 159) = v5;
        if ( v5 )
        {
          v6 = *v5;
          if ( *v5 )
          {
            do
            {
              if ( v4 )
                *v6 |= 0x40u;
              sub_5FBCC0(v3);
              v7 = *((_DWORD *)this + 159);
              if ( !v7 )
                break;
              v8 = *(_DWORD ***)(v7 + 4);
              *((_DWORD *)this + 159) = v8;
              if ( !v8 )
                break;
              v6 = *v8;
            }
            while ( *v8 );
          }
        }
      }
    }
  }
}
