// f1c  0x00448330  size=257
int __thiscall sub_448330(float *this, float a2)
{
  double v3; // st7
  int v4; // ebx
  int i; // edi
  int v6; // eax
  int v7; // ecx
  int v8; // ecx
  int result; // eax
  float v10; // [esp+Ch] [ebp-1Ch]
  _DWORD v11[3]; // [esp+10h] [ebp-18h] BYREF
  char v12[4]; // [esp+1Ch] [ebp-Ch] BYREF
  char v13[4]; // [esp+20h] [ebp-8h] BYREF
  char v14[4]; // [esp+24h] [ebp-4h] BYREF

  if ( this[2] > 0.0 )
  {
    v3 = a2 + this[5];
    sub_58957A(v3);
    v4 = sub_54C210(*(_DWORD *)this);
    for ( i = 0; i < v4; ++i )
    {
      v6 = sub_54C230(i);
      v10 = v3;
      sub_551810(v6, *((_DWORD *)this + 3), v10);
    }
  }
  sub_54B950(v12, v13, v14);
  v7 = *((_DWORD *)this + 1);
  memset(v11, 0, sizeof(v11));
  if ( v7 )
    (*(void (__thiscall **)(int, int, char *, _DWORD *, _DWORD, int, _DWORD))(*(_DWORD *)v7 + 4))(
      v7,
      2,
      v12,
      v11,
      LODWORD(flt_7CF2CC),
      1065353216,
      0);
  v8 = *((_DWORD *)this + 4);
  if ( v8 )
  {
    if ( a2 == this[6] )
      result = sub_550620(v8, 0);
    else
      result = sub_5505A0(v8, 0);
    this[6] = a2;
  }
  else
  {
    result = LODWORD(a2);
    this[6] = a2;
  }
  return result;
}
