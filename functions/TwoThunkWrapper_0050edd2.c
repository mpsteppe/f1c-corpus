int __stdcall sub_50EDD2(int a1, float a2, float a3, float a4)
{
  int v5[4]; // [esp+Ch] [ebp-10h] BYREF

  ThunkViaFunctionPointer((int)v5, a2, a3, a4);
  ThunkToIndirectCallViaDAT005d7860();
  return a1;
}
