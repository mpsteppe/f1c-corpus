unsigned int __thiscall sub_5B4A00(int this, const void *a2, const void *a3, int a4, unsigned int a5)
{
  unsigned int result; // eax
  int *v7; // ecx
  double i; // st7
  double v9; // st7
  int v10; // edi
  unsigned __int16 *v11; // esi
  unsigned __int16 v12; // bx
  __int64 v13; // rax
  unsigned __int16 v14; // bx
  _WORD v15[768]; // [esp+10h] [ebp-600h] BYREF

  result = *(_DWORD *)(this + 8632);
  if ( !result )
  {
    qmemcpy((void *)(this + 5204), a2, 0x600u);
    qmemcpy((void *)(this + 6740), a3, 0x600u);
    (*(void (__stdcall **)(_DWORD, _DWORD, int))(**(_DWORD **)(this + 4448) + 72))(
      *(_DWORD *)(this + 4448),
      0,
      this + 5204);
    v7 = *(int **)(this + 5196);
    *(_DWORD *)(this + 5200) = a4;
    sub_5AC740(v7, 1);
    sub_5AC620(*(LONG **)(this + 5196));
    result = a5;
    if ( a5 )
    {
      for ( i = sub_5AC8D0((unsigned int *)*(_DWORD *)(this + 5196));
            i < *(float *)(this + 5200);
            i = sub_5AC8D0((unsigned int *)*(_DWORD *)(this + 5196)) )
      {
        v9 = i / *(float *)(this + 5200);
        v10 = 0;
        v11 = (unsigned __int16 *)(this + 5204);
        do
        {
          v12 = v11[256];
          v15[v10] = *v11 + (__int64)((double)(v11[768] - *v11) * v9);
          v13 = (__int64)((double)(v11[1024] - v12) * v9);
          HIDWORD(v13) = v11[1280];
          LOWORD(v13) = v12 + v13;
          v14 = v11[512];
          v15[v10 + 256] = v13;
          ++v11;
          v15[v10++ + 512] = v14 + (__int64)((double)(HIDWORD(v13) - v14) * v9);
        }
        while ( v10 < 256 );
        (*(void (__stdcall **)(_DWORD, _DWORD, _WORD *))(**(_DWORD **)(this + 4448) + 72))(
          *(_DWORD *)(this + 4448),
          0,
          v15);
      }
      (*(void (__stdcall **)(_DWORD, _DWORD, int))(**(_DWORD **)(this + 4448) + 72))(
        *(_DWORD *)(this + 4448),
        0,
        this + 6740);
      result = sub_5AC680(*(_BYTE **)(this + 5196));
      *(_DWORD *)(this + 5200) = 0;
    }
  }
  return result;
}
