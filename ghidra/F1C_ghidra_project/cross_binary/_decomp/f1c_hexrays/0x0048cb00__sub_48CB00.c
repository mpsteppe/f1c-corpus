// f1c  0x0048cb00  size=281
void __thiscall sub_48CB00(float *this, float a2)
{
  int v3; // ebx
  double v4; // st7
  int v5; // eax
  int v6; // ebp
  char v7; // al
  int v8; // ecx
  bool v9; // zf
  bool v10; // sf
  int v11; // edi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // [esp+Ch] [ebp+4h]

  v3 = *((_DWORD *)this + 203) * *((_DWORD *)this + 202);
  if ( v3 > 0 )
  {
    v4 = a2 + this[208];
    this[208] = v4;
    v5 = sub_587BDC(v4 * 14.999999);
    if ( v5 > 0 )
    {
      v6 = v5;
      while ( 1 )
      {
        v7 = *((_BYTE *)this + 828);
        v8 = *((_DWORD *)this + 203) / 2 + *((_DWORD *)this + 203) * *((_DWORD *)this + 206) - *((_DWORD *)this + 205);
        v15 = v8;
        if ( !v7 )
          break;
        v9 = *((_DWORD *)this + 203) / 2 + *((_DWORD *)this + 203) * *((_DWORD *)this + 206) == *((_DWORD *)this + 205);
        if ( v8 < 0 )
        {
          v8 += v3;
          goto LABEL_9;
        }
LABEL_13:
        if ( !v9 )
        {
          v11 = 2 * (v7 != 0) - 1;
          v12 = sub_587BDC((double)v15 * 0.44400001);
          if ( v12 < 1 )
            v12 = 1;
          v13 = v11 * v12 + *((_DWORD *)this + 205);
          *((_DWORD *)this + 205) = v13;
          if ( v13 >= v3 )
          {
            do
              v13 -= v3;
            while ( v13 >= v3 );
            *((_DWORD *)this + 205) = v13;
          }
          v14 = *((_DWORD *)this + 205);
          if ( v14 < 0 )
          {
            do
              v14 += v3;
            while ( v14 < 0 );
            *((_DWORD *)this + 205) = v14;
          }
          (*(void (__thiscall **)(float *, int))(*(_DWORD *)this + 44))(this, 1);
        }
        --v6;
        this[208] = this[208] - 0.06666667;
        if ( !v6 )
          return;
      }
      v10 = v8 < 0;
      if ( v8 > 0 )
      {
        v8 = v3 - v8;
LABEL_9:
        v15 = v8;
        v10 = v8 < 0;
      }
      if ( v10 )
      {
        v8 = -v8;
        v15 = v8;
      }
      v9 = v8 == 0;
      goto LABEL_13;
    }
  }
}
