int __thiscall sub_548C20(int *this, int a2, int a3)
{
  int v4; // ecx
  int result; // eax
  int v6; // ebx
  int v7; // ebp
  float v8; // [esp+0h] [ebp-2Ch]
  float v9; // [esp+4h] [ebp-28h]
  float v10; // [esp+4h] [ebp-28h]
  float v11; // [esp+8h] [ebp-24h]
  float v12; // [esp+14h] [ebp-18h] BYREF
  float v13; // [esp+18h] [ebp-14h] BYREF
  float v14; // [esp+1Ch] [ebp-10h] BYREF
  float v15; // [esp+20h] [ebp-Ch] BYREF
  int v16; // [esp+24h] [ebp-8h] BYREF
  int v17; // [esp+28h] [ebp-4h] BYREF

  v4 = this[2];
  v14 = 0.0;
  v13 = 0.0;
  v12 = 0.0;
  v17 = 0;
  v15 = 0.0;
  v16 = 0;
  if ( v4 )
    sub_54B530(&v14, &v13, &v12, &v17, &v15, &v16);
  v11 = -v12;
  v9 = -v13 - 1.5;
  v8 = -v14;
  sub_541D10(*this, v8, v9, v11);
  v10 = -v15;
  sub_541DB0(*this, 1.5707964, v10, 0.0);
  result = *(_DWORD *)(a2 + 372);
  if ( result > 0 )
  {
    sub_5572B0(a2);
    sub_541A70((float *)*this);
    sub_541B70(*this, 14);
    v6 = 0;
    if ( *(int *)(a2 + 372) > 0 )
    {
      v7 = 0;
      do
      {
        sub_556930(*this);
        ++v6;
        v7 += 24;
      }
      while ( v6 < *(_DWORD *)(a2 + 372) );
    }
    return sub_5550E0(a2, *this);
  }
  return result;
}
