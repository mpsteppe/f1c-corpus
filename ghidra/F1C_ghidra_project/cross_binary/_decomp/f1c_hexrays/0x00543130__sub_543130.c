// f1c  0x00543130  size=221
int __stdcall sub_543130(const char *a1, _DWORD *a2, _DWORD *a3, int a4)
{
  int v4; // eax
  int v5; // esi
  int v7; // edi
  void *v8; // ebx
  char v9[256]; // [esp+Ch] [ebp-100h] BYREF

  v4 = sub_587DB0(a1, aRb);
  v5 = v4;
  if ( v4 )
  {
    sub_587F64(v4, 0, 2);
    v7 = sub_58ACE6(v5);
    sub_587F64(v5, 0, 0);
    v8 = (void *)sub_587C03(v7);
    sub_58803F(v8, 1, v7, v5);
    sub_587D02(v5);
    if ( sub_540050(dword_8B78A0, (int)v8, v7, a2, a3, a4) )
    {
      return -1;
    }
    else
    {
      sub_587BCF(v8);
      return 0;
    }
  }
  else
  {
    sub_58815F(v9, "Error opening bitmap file %s", a1);
    sub_53C590(-2, v9);
    return -2;
  }
}
