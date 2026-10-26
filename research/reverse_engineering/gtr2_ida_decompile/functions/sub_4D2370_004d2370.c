void __thiscall sub_4D2370(int this, float a2)
{
  int v2; // ebx
  int v3; // edi
  double v4; // st7
  int v5; // ebp
  int v6; // eax
  char v7; // bl
  int v8; // eax
  bool v9; // zf
  bool v10; // sf
  unsigned __int64 v11; // rax
  int v12; // eax
  int v13; // eax
  int v14; // [esp+Ch] [ebp-8h]
  int v15; // [esp+10h] [ebp-4h]
  int v16; // [esp+18h] [ebp+4h]

  v2 = *(_DWORD *)(this + 856);
  v3 = v2 * *(_DWORD *)(this + 852);
  if ( v3 > 0 )
  {
    v4 = a2 + *(float *)(this + 876);
    *(float *)(this + 876) = v4;
    if ( (int)(unsigned __int64)(v4 * 14.999999) > 0 )
    {
      v5 = v2 * *(_DWORD *)(this + 868);
      v6 = v2;
      v7 = *(_BYTE *)(this + 872);
      v15 = v6 / 2 + v5;
      v14 = (unsigned __int64)(v4 * 14.999999);
      while ( 1 )
      {
        v8 = v15 - *(_DWORD *)(this + 864);
        v16 = v8;
        if ( !v7 )
          break;
        v9 = v15 == *(_DWORD *)(this + 864);
        if ( v8 < 0 )
        {
          v8 += v3;
          goto LABEL_9;
        }
LABEL_13:
        if ( !v9 )
        {
          v11 = (unsigned __int64)((double)v16 * 0.44400001);
          if ( (int)v11 < 1 )
            LODWORD(v11) = 1;
          v12 = (2 * (v7 != 0) - 1) * v11 + *(_DWORD *)(this + 864);
          *(_DWORD *)(this + 864) = v12;
          if ( v12 >= v3 )
          {
            do
              v12 -= v3;
            while ( v12 >= v3 );
            *(_DWORD *)(this + 864) = v12;
          }
          v13 = *(_DWORD *)(this + 864);
          if ( v13 < 0 )
          {
            do
              v13 += v3;
            while ( v13 < 0 );
            *(_DWORD *)(this + 864) = v13;
          }
        }
        v9 = v14-- == 1;
        *(float *)(this + 876) = *(float *)(this + 876) - 0.06666667;
        if ( v9 )
          return;
      }
      v10 = v8 < 0;
      if ( v8 > 0 )
      {
        v8 = v3 - v8;
LABEL_9:
        v16 = v8;
        v10 = v8 < 0;
      }
      if ( v10 )
      {
        v8 = -v8;
        v16 = v8;
      }
      v9 = v8 == 0;
      goto LABEL_13;
    }
  }
}
