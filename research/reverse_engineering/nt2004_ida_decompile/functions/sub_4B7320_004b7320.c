int sub_4B7320()
{
  double v0; // st7
  double v1; // st6
  int v2; // ebp
  int v3; // edi
  int v4; // ebx
  float v6; // [esp+10h] [ebp-20h]
  float v7; // [esp+14h] [ebp-1Ch]
  int v8; // [esp+14h] [ebp-1Ch]
  int v9; // [esp+18h] [ebp-18h]
  int v10; // [esp+1Ch] [ebp-14h]
  int v11; // [esp+20h] [ebp-10h] BYREF
  int v12; // [esp+24h] [ebp-Ch] BYREF
  int v13; // [esp+28h] [ebp-8h] BYREF
  int v14; // [esp+2Ch] [ebp-4h] BYREF

  sub_506960(0);
  sub_5070D0(aTireInformatio, 0.5, 0.0099999998, dword_60911C, 2, -1.0, -1.0, 0, 0);
  sub_506B70(&v12, &v14, 0);
  sub_506B50(&v11, &v13);
  v0 = (double)v11;
  v1 = (double)v12;
  v2 = (__int64)(v0 * 0.079999998 + v1);
  v6 = (float)v13;
  v7 = (float)v14;
  v9 = (__int64)(v6 * 0.51999998 + v7);
  v10 = (__int64)(v0 * 0.57700002 + v1);
  v8 = (__int64)(v6 * 0.94999999 + v7);
  v3 = (__int64)(v0 * 0.347);
  v4 = (__int64)(v6 * 0.039000001);
  sub_4B6FD0(0, v2, v9, v3, v4);
  sub_4B6FD0(1, v10, v9, v3, v4);
  sub_4B6FD0(2, v2, v8, v3, v4);
  sub_4B6FD0(3, v10, v8, v3, v4);
  sub_4B70F0(0, 0.109, 0.375);
  sub_4B70F0(1, 0.60000002, 0.375);
  sub_4B70F0(2, 0.109, 0.79000002);
  return sub_4B70F0(3, 0.60000002, 0.79000002);
}
