void __thiscall sub_468080(int this, int a2, int a3)
{
  int v4; // eax
  char *v5; // eax
  char *v6; // ecx
  char *v7; // [esp+8h] [ebp-E0h]
  int v8; // [esp+10h] [ebp-D8h] BYREF
  char v9[16]; // [esp+14h] [ebp-D4h] BYREF
  char Buffer[80]; // [esp+24h] [ebp-C4h] BYREF
  char v11[4]; // [esp+74h] [ebp-74h] BYREF
  char Destination[112]; // [esp+78h] [ebp-70h] BYREF

  v4 = *(_DWORD *)(this + 92);
  Buffer[0] = 0;
  if ( v4 )
  {
    sprintf(Buffer, "%s There is a vote in progress.", aCannotCallVote);
LABEL_8:
    sub_468300(Buffer);
    return;
  }
  if ( -15.0 < *(float *)(this + 76) )
  {
    sprintf(
      Buffer,
      "%s Vote just ended.  Wait %d seconds.",
      aCannotCallVote,
      (unsigned int)(__int64)(*(float *)(this + 76) + 15.0 + 1.0));
    sub_468300(Buffer);
    return;
  }
  if ( a2 == 1 && dword_75CBB0 == 7 )
  {
    sprintf(Buffer, "%s Cannot advance session past race.", aCannotCallVote);
    goto LABEL_8;
  }
  *(_DWORD *)(this + 76) = 1110704128;
  ++*(_DWORD *)(this + 80);
  *(_DWORD *)(this + 92) = a2;
  *(_DWORD *)(this + 88) = NumOfElements;
  *(_DWORD *)(this + 84) = (__int64)((double)*(int *)(this + 88) * 0.50999999 + 1.0);
  *(_DWORD *)(this + 288) = 0;
  *(_DWORD *)(this + 292) = 0;
  sub_467E40((_DWORD *)this, a3, 1, 1);
  sub_462BC0(v11);
  sub_463CD0(dword_764D70, a3, v11, &v8);
  if ( sub_462C60(v11, 1) )
  {
    strncpy(Destination, aServer, 0x1Fu);
    Destination[31] = 0;
  }
  v7 = (char *)operator new(0x80u);
  *v7 = 0;
  sub_578560(word_5FD024);
  if ( *(_DWORD *)(this + 92) == 1 )
  {
    v5 = aAdvanceToNextS;
  }
  else if ( *(_DWORD *)(this + 92) == 2 )
  {
    v5 = aAdvanceToNextE;
  }
  else
  {
    v5 = aNoIssue;
  }
  sub_578560(v5);
  sub_578560(aProposedBy);
  sub_578560(Destination);
  sub_578560(word_5FC804);
  sub_578560(aVoteNeeds);
  sprintf(v9, "%d", *(_DWORD *)(this + 84) - *(_DWORD *)(this + 288));
  sub_578560(v9);
  sub_578560(aToPass);
  v6 = v7;
  if ( !v7 )
    v6 = &byte_629120;
  sub_468300(v6);
  if ( v7 )
    sub_5BE8AE(v7);
  nullsub_6(v11);
}
