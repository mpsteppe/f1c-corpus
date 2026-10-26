bool __thiscall sub_643F30(void *this, char *FileName, int a3, int a4)
{
  const char *v5; // edx
  bool v6; // bl
  void *v8[2]; // [esp+8h] [ebp-24h] BYREF
  int (__thiscall **v9)(void *, char); // [esp+10h] [ebp-1Ch] BYREF
  char *Mode; // [esp+14h] [ebp-18h]
  int v11; // [esp+18h] [ebp-14h]
  int v12; // [esp+1Ch] [ebp-10h]
  int v13; // [esp+20h] [ebp-Ch]
  int v14; // [esp+28h] [ebp-4h]
  void *retaddr; // [esp+2Ch] [ebp+0h]

  if ( *((_DWORD *)this + 1) )
    (*(void (__thiscall **)(void *))(*(_DWORD *)this + 112))(this);
  v9 = &off_6F197C;
  Mode = 0;
  v11 = 0;
  v12 = 0;
  sub_5A8860(&v9, 0, 0);
  v13 = 0;
  if ( retaddr == (void *)1 )
  {
    sub_5A8920(v8, (int)this, (int)"r", 1u);
  }
  else if ( retaddr == (void *)2 )
  {
    sub_5A8920(v8, (int)this, (int)"w", 1u);
  }
  else if ( retaddr == (void *)3 )
  {
    sub_5A8920(v8, (int)this, (int)&unk_735FD8, 2u);
  }
  else if ( retaddr == (void *)4 )
  {
    sub_5A8920(v8, (int)this, (int)&unk_735FD4, 2u);
  }
  else if ( retaddr == (void *)5 )
  {
    sub_5A8920(v8, (int)this, (int)"a", 1u);
  }
  else if ( retaddr == (void *)6 )
  {
    sub_5A8920(v8, (int)this, (int)&unk_735FD0, 2u);
  }
  v5 = "b";
  if ( !(_BYTE)FileName )
    v5 = "t";
  strlen(v5);
  sub_5A88C0();
  *((_DWORD *)this + 1) = fopen(FileName, Mode);
  *((_DWORD *)this + 2) = retaddr;
  sub_5A8920((void **)this + 3, (int)this, (int)FileName, strlen(FileName));
  v6 = *((_DWORD *)this + 1) != 0;
  v14 = -1;
  sub_5A8840();
  return v6;
}
