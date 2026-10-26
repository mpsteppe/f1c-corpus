// f1c  0x0045f390  size=272
char __thiscall sub_45F390(_DWORD *this)
{
  double v2; // st7
  double v3; // st7
  float v5; // [esp+Ch] [ebp-60h]
  float v6; // [esp+10h] [ebp-5Ch]
  float v7; // [esp+14h] [ebp-58h] BYREF
  char *v8; // [esp+18h] [ebp-54h] BYREF
  _BYTE v9[4]; // [esp+1Ch] [ebp-50h] BYREF
  _BYTE v10[76]; // [esp+20h] [ebp-4Ch] BYREF

  if ( this[4081] != 3 )
    return 0;
  sub_568BA0(v10);
  sub_568BE0(1);
  sub_568C60(v10);
  v2 = 0.0;
  v5 = 0.0;
  v6 = 0.0;
  while ( 1 )
  {
    if ( v2 <= 0.0 )
    {
      sub_57A5A0(this[4078]);
      v5 = 4.0;
    }
    if ( (unsigned __int8)sub_57A610(&v7, &v8, v9) )
      break;
    v3 = sub_568CF0(v10);
    v6 = v6 + v3;
    v2 = v5 - v3;
    v5 = v2;
    if ( v6 >= 60.0 )
    {
      nullsub_3(v10);
      return 0;
    }
  }
  sub_4F9FC0(v7);
  sub_42BDA0(v7);
  sub_42CF10(&dword_7C569C, *v8);
  sub_45C8B0(this + 26864, 0);
  nullsub_3(v10);
  return 1;
}
