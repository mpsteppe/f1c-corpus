void __thiscall sub_5C22D0(void *this)
{
  int v2; // eax
  int v3; // ecx
  _DWORD *v4; // ecx
  int v5; // eax
  int v6; // ecx
  _DWORD v7[10]; // [esp+4h] [ebp-5Ch] BYREF
  _DWORD v8[10]; // [esp+2Ch] [ebp-34h] BYREF
  int v9; // [esp+5Ch] [ebp-4h]

  if ( *(_DWORD *)this )
  {
    if ( !(*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)this + 3) + 12))(*((_DWORD *)this + 3)) )
    {
      v2 = *((_DWORD *)this + 2);
      qmemcpy(v7, (const void *)v2, sizeof(v7));
      v9 = 0;
      nullsub_7((void *)(v2 + 4));
      memcpy(*((void **)this + 2), (const void *)(*((_DWORD *)this + 2) + 40), 40 * (*(_DWORD *)this - 1));
      v3 = v7[0];
      --*(_DWORD *)this;
      (*(void (__thiscall **)(_DWORD, int, _DWORD *))(**((_DWORD **)this + 3) + 32))(*((_DWORD *)this + 3), v3, &v7[1]);
      v4 = &v7[1];
LABEL_9:
      v9 = -1;
      nullsub_7(v4);
      return;
    }
    v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 3) + 28))(*((_DWORD *)this + 3));
    if ( v5 )
    {
      if ( (v6 = *(_DWORD *)(v5 + 48), v6 != -1) && *(_DWORD *)(v5 + 44) >= v6 || *(_BYTE *)(v5 + 81) )
      {
        qmemcpy(v8, *((const void **)this + 2), sizeof(v8));
        v9 = 1;
        sub_5C2250();
        (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD *))(**((_DWORD **)this + 3) + 32))(
          *((_DWORD *)this + 3),
          v8[0],
          &v8[1]);
        v4 = &v8[1];
        goto LABEL_9;
      }
    }
  }
}
