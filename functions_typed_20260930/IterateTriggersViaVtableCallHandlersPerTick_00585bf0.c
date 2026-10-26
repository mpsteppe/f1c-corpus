char __thiscall sub_585BF0(void *this)
{
  int v2; // edi
  int v3; // ebp
  int *v4; // ebx
  __int64 v5; // rax
  int v7; // [esp-8h] [ebp-30h]
  int v8; // [esp-4h] [ebp-2Ch]
  int v9; // [esp+0h] [ebp-28h]
  int v10; // [esp+14h] [ebp-14h] BYREF
  int v11; // [esp+18h] [ebp-10h] BYREF
  int v12; // [esp+1Ch] [ebp-Ch]
  int v13; // [esp+20h] [ebp-8h]
  int v14; // [esp+24h] [ebp-4h]

  (*(void (__thiscall **)(void *))(*(_DWORD *)this + 200))(this);
  v2 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 28))(this);
  v3 = 0;
  v14 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 164))(this);
  v12 = 0;
  if ( v14 > 0 )
  {
    do
    {
      if ( (*(unsigned __int8 (__thiscall **)(void *, int, int))(*(_DWORD *)this + 172))(this, v3, v2) )
      {
        v11 = 0;
        v10 = 0;
        DualQueryIntoTwoOutputParams(&v11, &v10);
        v4 = (int *)FieldGetter_5cc0(this);
        v9 = v10;
        v8 = v11;
        v13 = *v4;
        v7 = sub_587220(v2);
        v5 = ReadFieldAtOffset0x14(v2);
        v3 = v12;
        (*(void (__fastcall **)(int *, _DWORD, int, _DWORD, int, int, int))(v13 + 52))(
          v4,
          HIDWORD(v5),
          v12,
          v5,
          v7,
          v8,
          v9);
        EmptyStub_0170();
      }
      v12 = ++v3;
    }
    while ( v3 < v14 );
  }
  (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 32))(this, v2);
  (*(void (__thiscall **)(void *))(*(_DWORD *)this + 204))(this);
  return 1;
}

