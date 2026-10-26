int __thiscall sub_46C4F0(_DWORD *this, int a2, signed int a3)
{
  signed int v3; // eax
  int v5; // edi
  int v7; // [esp+28h] [ebp-110h]
  _BYTE v8[256]; // [esp+38h] [ebp-100h] BYREF

  v3 = 0;
  if ( a3 > 0 )
  {
    memset(v8, 0x20u, a3);
    v3 = a3;
  }
  v8[v3] = 0;
  if ( !*this || (int)this[1] < 4 )
    return 1;
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s%s\n", v8, "MovementPath");
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s{\n", v8);
  v5 = 0;
  if ( (int)this[1] > 0 )
  {
    v7 = 0;
    do
    {
      (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(
        a2,
        "%s  ControlPoint=(%f, %f, %f)\n",
        v8,
        *(float *)(v7 + *this),
        *(float *)(v7 + *this + 4),
        *(float *)(v7 + *this + 8));
      ++v5;
      v7 += 28;
    }
    while ( v5 < this[1] );
  }
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s}\n", v8);
  return 0;
}
