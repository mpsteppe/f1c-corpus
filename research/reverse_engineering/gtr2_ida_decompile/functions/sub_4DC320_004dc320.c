int __thiscall sub_4DC320(_DWORD *this)
{
  _DWORD *v2; // edi
  int v3; // ebx
  char v5[4]; // [esp+8h] [ebp-104h] BYREF
  int v6[64]; // [esp+Ch] [ebp-100h] BYREF

  v2 = this + 23;
  (*(void (__thiscall **)(_DWORD *))(this[23] + 44))(this + 23);
  v3 = 32;
  if ( sub_4DAC90(this) )
  {
    do
    {
      if ( sub_6131C0("SOURCE_MAS", (int)v6) && !(unsigned __int8)sub_4DFFB0(this[194], v6) )
        sprintf(String1, "Could Not Load MAS file %s (line %d)", v5, this[188]);
      --v3;
    }
    while ( v3 >= 0 && sub_4DAC90(this) );
  }
  (*(void (__thiscall **)(_DWORD *))(*v2 + 44))(v2);
  return 0;
}
