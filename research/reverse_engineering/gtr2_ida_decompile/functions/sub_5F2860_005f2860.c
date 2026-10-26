int __thiscall sub_5F2860(int this, const void *a2, const void *a3, int a4, int a5)
{
  int result; // eax
  double i; // st7
  double v8; // st7
  int v9; // edi
  unsigned __int16 *v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int64 v12; // rax
  unsigned __int16 v13; // bx
  _WORD v14[768]; // [esp+14h] [ebp-600h] BYREF

  result = *(_DWORD *)(this + 9432);
  if ( !result )
  {
    qmemcpy((void *)(this + 5908), a2, 0x600u);
    qmemcpy((void *)(this + 7444), a3, 0x600u);
    (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, int))(**(_DWORD **)(this + 9548) + 84))(
      *(_DWORD *)(this + 9548),
      0,
      0,
      this + 5908);
    *(_DWORD *)(this + 5904) = a4;
    sub_5F5C70(1);
    sub_5F5B90(*(_DWORD *)(this + 5900));
    result = a5;
    if ( a5 )
    {
      for ( i = sub_5F5900(*(_DWORD *)(this + 5900)); i < *(float *)(this + 5904); i = sub_5F5900(*(_DWORD *)(this + 5900)) )
      {
        v8 = i / *(float *)(this + 5904);
        v9 = 0;
        v10 = (unsigned __int16 *)(this + 5908);
        do
        {
          v11 = v10[256];
          v14[v9] = *v10 + (unsigned __int64)((double)(v10[768] - *v10) * v8);
          v12 = (unsigned __int64)((double)(v10[1024] - v11) * v8);
          HIDWORD(v12) = v10[1280];
          LOWORD(v12) = v11 + v12;
          v13 = v10[512];
          v14[v9 + 256] = v12;
          ++v10;
          v14[v9++ + 512] = v13 + (unsigned __int64)((double)(HIDWORD(v12) - v13) * v8);
        }
        while ( v9 < 256 );
        (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, _WORD *))(**(_DWORD **)(this + 9548) + 84))(
          *(_DWORD *)(this + 9548),
          0,
          0,
          v14);
      }
      (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, int))(**(_DWORD **)(this + 9548) + 84))(
        *(_DWORD *)(this + 9548),
        0,
        0,
        this + 7444);
      result = sub_5F5BC0(*(_DWORD *)(this + 5900));
      *(_DWORD *)(this + 5904) = 0;
    }
  }
  return result;
}
