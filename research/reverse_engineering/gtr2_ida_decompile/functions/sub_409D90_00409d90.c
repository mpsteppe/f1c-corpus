void __thiscall sub_409D90(int *this)
{
  const char *v2; // eax
  int v3; // ebx
  int v4; // ebp
  int v5; // edi
  int *v6; // ecx
  int v7; // edx
  int v8; // eax
  int v9; // edx
  float v10; // [esp+4h] [ebp-18h] BYREF
  _DWORD v11[2]; // [esp+8h] [ebp-14h] BYREF
  int v12; // [esp+10h] [ebp-Ch]
  int v13; // [esp+14h] [ebp-8h]
  int v14; // [esp+18h] [ebp-4h]

  if ( *(_DWORD *)(*this + 32) )
  {
    if ( !dword_B6E090 || (v2 = (const char *)sub_4DEFD0()) != 0 && !_stricmp(v2, "MAIN MENU") )
    {
      if ( dword_B640C0 == 2 )
      {
        v3 = dword_B6A33C;
        v4 = dword_B6A338;
        v5 = *this;
        v12 = dword_B6A3D8;
        v11[0] = dword_B6A338;
        v11[1] = dword_B6A33C;
        v13 = dword_B6A3DC;
        v14 = dword_B6A3E0;
        if ( sub_409A40(v11, (_DWORD *)v5) )
        {
          v10 = dbl_FB1D08;
          sub_401760(&v10, 0.0, 0.5);
          *(float *)(v5 + 28) = v10 + *(float *)(v5 + 28);
        }
        else
        {
          *(_DWORD *)(v5 + 28) = 0;
        }
        v6 = (int *)*this;
        v7 = v12;
        v8 = v13;
        *v6 = v4;
        v6[1] = v3;
        v6[2] = v7;
        v9 = v14;
        v6[3] = v8;
        v6[4] = v9;
        if ( *(float *)(*this + 28) >= (double)*(float *)(*this + 24) )
        {
          sub_409BC0(*this);
          *(_DWORD *)(*this + 28) = 0;
        }
      }
      else if ( dword_B640C0 == 5 && *(_BYTE *)(*this + 20) )
      {
        sub_540850(-1.0);
        if ( !*(_BYTE *)(*this + 21) )
        {
          sub_409CD0((_DWORD *)*this);
          *(_BYTE *)(*this + 21) = 1;
        }
      }
    }
    else
    {
      *(_DWORD *)(*this + 28) = 0;
    }
  }
}
