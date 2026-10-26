void __thiscall sub_4F7C90(int this, int a2)
{
  int v3; // ecx
  _BYTE *v4; // ecx
  _DWORD *v5; // edi
  _DWORD *v6; // edi
  _DWORD *v7; // edi
  int v8; // edi
  int v9; // eax
  int v10; // ebp
  int v11; // eax

  v3 = *(_DWORD *)(this + 136);
  *(_BYTE *)(this + 8) = 0;
  if ( v3 )
  {
    if ( !*(_BYTE *)(this + 9) || (_BYTE)a2 )
    {
      sub_5DB5A0();
      v4 = *(_BYTE **)(this + 140);
      if ( v4 )
        sub_405F00(v4, 0);
      if ( *(_DWORD *)(this + 192) )
      {
        sub_4F7C90(a2);
        v5 = *(_DWORD **)(this + 216);
        if ( v5 )
        {
          (*(void (__thiscall **)(_DWORD *, _DWORD))(*v5 + 20))(v5, 0);
          v5[5] = 0;
        }
        *(_DWORD *)(this + 192) = 0;
      }
      if ( *(_DWORD *)(this + 196) )
      {
        sub_4F7C90(a2);
        v6 = *(_DWORD **)(this + 220);
        if ( v6 )
        {
          (*(void (__thiscall **)(_DWORD *, _DWORD))(*v6 + 20))(v6, 0);
          v6[5] = 0;
        }
        *(_DWORD *)(this + 196) = 0;
      }
      if ( *(_DWORD *)(this + 200) )
      {
        sub_4F7C90(a2);
        v7 = *(_DWORD **)(this + 224);
        if ( v7 )
        {
          (*(void (__thiscall **)(_DWORD *, _DWORD))(*v7 + 20))(v7, 0);
          v7[5] = 0;
        }
        *(_DWORD *)(this + 200) = 0;
      }
      v8 = *(_DWORD *)(this + 168);
      if ( v8 )
      {
        v9 = *(_DWORD *)(this + 140);
        if ( v9 )
        {
          v10 = *(_DWORD *)(v9 + 8);
          if ( (unsigned __int8)sub_405250() )
            sub_5BC080(v10, v8, 0);
        }
        *(_DWORD *)(this + 168) = 0;
      }
      v11 = *(_DWORD *)(this + 140);
      if ( v11 )
        sub_4F26B0(*(_DWORD **)(*(_DWORD *)(*(_DWORD *)(v11 + 8) + 532) + 8));
      *(_DWORD *)(this + 160) = 0;
      *(_BYTE *)(this + 14) = 1;
    }
    else
    {
      sub_4F7BF0();
      *(_BYTE *)(this + 14) = 1;
    }
  }
}
