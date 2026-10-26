bool __stdcall sub_4A7560(int a1, int a2, int a3)
{
  int v3; // edi
  int v4; // ebx
  int v6; // [esp+Ch] [ebp-4h] BYREF

  v3 = (__int64)((double)dword_6152E8 * 0.00125 * (double)a2);
  v4 = (__int64)((double)dword_6152EC * 0.0016666667 * (double)a3);
  sub_506B70(&a3, &v6, 0);
  sub_506B50(&a2, &a1);
  return v3 >= a3 && v3 <= a3 + a2 && v4 >= v6 && v4 <= v6 + a1;
}
