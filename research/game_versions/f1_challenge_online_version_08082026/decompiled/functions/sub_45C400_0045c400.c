char __thiscall sub_45C400(unsigned __int8 *this, int a2, _DWORD *a3)
{
  char v4; // bl
  int v6; // [esp+10h] [ebp-3788h] BYREF
  LPVOID v7[3]; // [esp+14h] [ebp-3784h] BYREF
  LPVOID v8; // [esp+20h] [ebp-3778h]
  LPVOID v9; // [esp+28h] [ebp-3770h]
  LPVOID v10; // [esp+30h] [ebp-3768h]
  LPVOID v11; // [esp+38h] [ebp-3760h]
  LPVOID v12; // [esp+40h] [ebp-3758h]
  char v13[104]; // [esp+1A7Ch] [ebp-1D1Ch] BYREF
  LPVOID v14; // [esp+1AE4h] [ebp-1CB4h]
  _DWORD v15[235]; // [esp+33ECh] [ebp-3ACh] BYREF

  v4 = 1;
  sub_42E320(v13);
  sub_4F34E0(v7);
  sub_4F4270(a2, v13, 2);
  *a3 = 0;
  if ( (unsigned __int8)sub_568A60(this[1], &v6) )
    *a3 += v6;
  else
    v4 = 0;
  if ( (unsigned __int8)sub_568A60(this[1], &v6) )
    *a3 += v6;
  else
    v4 = 0;
  *a3 += v7[2];
  if ( (unsigned __int8)sub_568A60(this[1], &v6) )
    *a3 += v6;
  else
    v4 = 0;
  if ( (unsigned __int8)sub_568A60(this[1], &v6) )
    *a3 += v6;
  else
    v4 = 0;
  if ( (unsigned __int8)sub_568A60(this[1], &v6) )
    *a3 += v6;
  else
    v4 = 0;
  if ( (unsigned __int8)sub_568A60(this[1], &v6) )
    *a3 += v6;
  else
    v4 = 0;
  if ( (unsigned __int8)sub_568A60(this[1], &v6) )
    *a3 += v6;
  else
    v4 = 0;
  if ( v12 )
    sub_587BCF(v12);
  if ( v11 )
    sub_587BCF(v11);
  if ( v10 )
    sub_587BCF(v10);
  if ( v9 )
    sub_587BCF(v9);
  if ( v8 )
    sub_587BCF(v8);
  if ( v7[0] )
    sub_587BCF(v7[0]);
  sub_42DDD0(v15);
  if ( v14 )
    sub_587BCF(v14);
  return v4;
}
