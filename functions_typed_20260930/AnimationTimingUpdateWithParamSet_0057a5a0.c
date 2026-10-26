int __thiscall sub_57A5A0(_DWORD *this)
{
  unsigned __int64 v2; // st7
  int v3; // edi
  _BYTE v5[4]; // [esp+10h] [ebp-4h] BYREF

  *(double *)&v2 = MutexGuardedTimerRead(*this);
  CounterAssignment(v5, v2, HIDWORD(v2));
  v3 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*this + 88))(*this);
  sub_586800(0, 14, 0, 3, 500);
  *(_BYTE *)(*(_DWORD *)(v3 + 72) + 4) = 1;
  SingleFunctionCallWrapper_6a00(v5, 4);
  return VTableDispatchWithConditionalCall(v3);
}

