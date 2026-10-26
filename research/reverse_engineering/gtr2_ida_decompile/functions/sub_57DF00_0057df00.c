void __thiscall sub_57DF00(int *this)
{
  float v2; // [esp+Ch] [ebp-34h]
  float v3; // [esp+10h] [ebp-30h] BYREF
  float v4; // [esp+14h] [ebp-2Ch]
  float v5; // [esp+18h] [ebp-28h]
  float v6; // [esp+1Ch] [ebp-24h] BYREF
  float v7; // [esp+20h] [ebp-20h]
  float v8; // [esp+24h] [ebp-1Ch]
  float v9[3]; // [esp+28h] [ebp-18h] BYREF
  _BYTE v10[12]; // [esp+34h] [ebp-Ch] BYREF

  v2 = 1.0;
  if ( this[1] != *(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468) )
  {
    sub_54FDF0(dword_FADD40, *this, (int)v9, (int)v10);
    sub_577780((float *)this, &v3, &v6);
    v6 = v9[0] - v3;
    v3 = v6;
    v7 = v9[1] - v4;
    v4 = v7;
    v8 = v9[2] - v5;
    v5 = v8;
    if ( v8 * v8 + v7 * v7 + v6 * v6 < 4.0 )
      v2 = *(float *)&dword_B7120C;
  }
  sub_56FFF0((int)(this + 672), v2);
}
