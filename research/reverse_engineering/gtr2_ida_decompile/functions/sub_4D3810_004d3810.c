bool __stdcall sub_4D3810(int a1, int a2, int a3)
{
  int v3; // edi
  int v4; // ebx
  int v6; // [esp+Ch] [ebp-4h] BYREF

  v3 = (unsigned __int64)((double)*(int *)dword_903EB8 * 0.00125 * (double)a2);
  v4 = (unsigned __int64)((double)dword_903EBC * 0.0016666667 * (double)a3);
  sub_567EA0(&a3, &v6, 0);
  sub_567E80(&a2, &a1);
  return v3 >= a3 && v3 <= a3 + a2 && v4 >= v6 && v4 <= v6 + a1;
}
