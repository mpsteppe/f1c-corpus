int __thiscall sub_48A8D0(float *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // edi
  int v5; // edi
  int v7; // [esp+4h] [ebp-8h] BYREF
  _BYTE v8[4]; // [esp+8h] [ebp-4h] BYREF

  DualFieldRead(v8, &v7);
  this[82] = FunctionCallWrapper_8940(*((_DWORD *)this + 16));
  (*(void (__thiscall **)(float *, int))(*(_DWORD *)this + 44))(this, 1);
  if ( *((_BYTE *)this + 326) && *((int *)this + 88) > 0 )
  {
    v2 = (*(int (__thiscall **)(float *))(*(_DWORD *)this + 28))(this);
    v3 = v7 - *((_DWORD *)this + 87) / 2 - v2;
    *((_DWORD *)this + 84) = v3;
    if ( v3 < 0 )
      this[84] = 0.0;
    v4 = (*(int (__thiscall **)(float *))(*(_DWORD *)this + 36))(this) - *((_DWORD *)this + 87);
    if ( *((_DWORD *)this + 84) > v4 - (*(int (__thiscall **)(float *))(*(_DWORD *)this + 28))(this) )
    {
      v5 = (*(int (__thiscall **)(float *))(*(_DWORD *)this + 36))(this) - *((_DWORD *)this + 87);
      *((_DWORD *)this + 84) = v5 - (*(int (__thiscall **)(float *))(*(_DWORD *)this + 28))(this);
    }
    ShortComputation_9ee0(this);
  }
  if ( this[82] > 0.25 && this[82] > 0.2 )
  {
    if ( *((_BYTE *)this + 324) )
    {
      DecrementCounterVirtualCall(this);
      return 0;
    }
    if ( *((_BYTE *)this + 325) )
      UINavigationAdvanceHandler(this);
  }
  return 0;
}

