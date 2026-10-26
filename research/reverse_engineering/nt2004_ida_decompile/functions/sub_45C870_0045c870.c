double __thiscall sub_45C870(int this)
{
  int v2; // ebx
  int v3; // esi
  float v5; // [esp+8h] [ebp-14h]
  float v6; // [esp+Ch] [ebp-10h] BYREF
  int v7; // [esp+10h] [ebp-Ch] BYREF
  int v8; // [esp+14h] [ebp-8h] BYREF
  int v9; // [esp+18h] [ebp-4h]

  v2 = 0;
  v9 = sub_45CE00();
  v5 = 0.0;
  if ( v9 > 0 )
  {
    do
    {
      v3 = sub_45C830((float *)this, v2);
      v6 = 0.0;
      sub_4598D0((_DWORD *)(this + 4), &v8, &v7);
      sub_5071A0(140 * v3 + this + 68, v8, v7, &v6, 0, 0);
      if ( v6 > (double)v5 )
        v5 = v6;
      ++v2;
    }
    while ( v2 < v9 );
  }
  return v5;
}
