void arinc429_pack_DataForKRP(const struct DataForKRP *o, uint32_t *arr, unsigned int *len)
{

uint32_t tmp_word;

arr[0] &= ~(0x3u << 8);
arr[0] |= (o->Mode & 0x3u) << 8;

arr[0] &= ~(0xFFFFu << 10);
arr[0] |= (o->ARSNumber & 0xFFFFu) << 10;

memcpy(&tmp_word, &o->Frequency, sizeof(tmp_word));

arr[1] &= ~(0x7FFFFFu << 8);
arr[1] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[2] &= ~(0x1FFu << 8);
arr[2] |= (tmp_word & 0x1FFu) << 8;

memcpy(&tmp_word, &o->KUR, sizeof(tmp_word));

arr[3] &= ~(0x7FFFFFu << 8);
arr[3] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[2] &= ~(0x1FFu << 17);
arr[2] |= (tmp_word & 0x1FFu) << 17;

arr[4] &= ~(0xFFu << 8);
arr[4] |= (o->SignalStrength & 0xFFu) << 8;

arr[5] &= ~(0xFFFFu << 8);
arr[5] |= (o->ControlResult & 0xFFFFu) << 8;

arr[0] &= ~(0x1u << 26);
arr[0] |= (o->CoordinateSymptom & 0x1u) << 26;

memcpy(&tmp_word, &o->ARSLatitude, sizeof(tmp_word));

arr[6] &= ~(0x7FFFFFu << 8);
arr[6] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[4] &= ~(0x1FFu << 16);
arr[4] |= (tmp_word & 0x1FFu) << 16;

memcpy(&tmp_word, &o->ARSLongitude, sizeof(tmp_word));

arr[7] &= ~(0x7FFFFFu << 8);
arr[7] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[8] &= ~(0x1FFu << 8);
arr[8] |= (tmp_word & 0x1FFu) << 8;

memcpy(&tmp_word, &o->Latitude, sizeof(tmp_word));

arr[9] &= ~(0x7FFFFFu << 8);
arr[9] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[8] &= ~(0x1FFu << 17);
arr[8] |= (tmp_word & 0x1FFu) << 17;

memcpy(&tmp_word, ((char *)&o->Latitude) + 4, sizeof(tmp_word));

arr[10] &= ~(0x7FFFFFu << 8);
arr[10] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[11] &= ~(0x1FFu << 8);
arr[11] |= (tmp_word & 0x1FFu) << 8;

memcpy(&tmp_word, &o->Longitude, sizeof(tmp_word));

arr[12] &= ~(0x7FFFFFu << 8);
arr[12] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[11] &= ~(0x1FFu << 17);
arr[11] |= (tmp_word & 0x1FFu) << 17;

memcpy(&tmp_word, ((char *)&o->Longitude) + 4, sizeof(tmp_word));

arr[13] &= ~(0x7FFFFFu << 8);
arr[13] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[14] &= ~(0x1FFu << 8);
arr[14] |= (tmp_word & 0x1FFu) << 8;

memcpy(&tmp_word, &o->Altitude, sizeof(tmp_word));

arr[15] &= ~(0x7FFFFFu << 8);
arr[15] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[14] &= ~(0x1FFu << 17);
arr[14] |= (tmp_word & 0x1FFu) << 17;

memcpy(&tmp_word, &o->SpeedNorth, sizeof(tmp_word));

arr[16] &= ~(0x7FFFFFu << 8);
arr[16] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[17] &= ~(0x1FFu << 8);
arr[17] |= (tmp_word & 0x1FFu) << 8;

memcpy(&tmp_word, &o->SpeedEastern, sizeof(tmp_word));

arr[18] &= ~(0x7FFFFFu << 8);
arr[18] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[17] &= ~(0x1FFu << 17);
arr[17] |= (tmp_word & 0x1FFu) << 17;

memcpy(&tmp_word, &o->SpeedVertical, sizeof(tmp_word));

arr[19] &= ~(0x7FFFFFu << 8);
arr[19] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[20] &= ~(0x1FFu << 8);
arr[20] |= (tmp_word & 0x1FFu) << 8;

arr[21] &= ~(0x3FFFFu << 8);
arr[21] |= (o->Time & 0x3FFFFu) << 8;

arr[22] &= ~(0x1FFFFFu << 8);
arr[22] |= (o->TimeLabel & 0x1FFFFFu) << 8;

arr[23] &= ~(0xFFFFu << 8);
arr[23] |= (o->Date & 0xFFFFu) << 8;

arr[24] &= ~(0x7FFFu << 8);
arr[24] |= (o->GDOP & 0x7FFFu) << 8;

arr[25] &= ~(0x1FFFFFu << 8);
arr[25] |= (o->SRNSState & 0x1FFFFFu) << 8;

arr[26] &= ~(0x7FFFFu << 8);
arr[26] |= (o->TechnoSRNS & 0x7FFFFu) << 8;

arr[27] &= ~(0x3FFFFFu << 8);
arr[27] |= (o->TechnoSputnic & 0x3FFFFFu) << 8;

arr[28] &= ~(0xFFFFu << 8);
arr[28] |= (o->TechnoAzimuth & 0xFFFFu) << 8;

arr[0] &= ~(0x1u << 27);
arr[0] |= (o->ARSNewCoordinates & 0x1u) << 27;

arr[0] &= ~(0x1u << 28);
arr[0] |= (o->sms_valid & 0x1u) << 28;

memcpy(&tmp_word, &o->sms, sizeof(tmp_word));

arr[29] &= ~(0x7FFFFFu << 8);
arr[29] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[20] &= ~(0x1FFu << 17);
arr[20] |= (tmp_word & 0x1FFu) << 17;

memcpy(&tmp_word, ((char *)&o->sms) + 4, sizeof(tmp_word));

arr[30] &= ~(0x7FFFFFu << 8);
arr[30] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[31] &= ~(0x1FFu << 8);
arr[31] |= (tmp_word & 0x1FFu) << 8;

arr[0] &= ~(0x3u << 29);
arr[0] |= (o->State & 0x3u) << 29;

memcpy(&tmp_word, &o->Checksum, sizeof(tmp_word));

arr[32] &= ~(0x7FFFFFu << 8);
arr[32] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[31] &= ~(0x1FFu << 17);
arr[31] |= (tmp_word & 0x1FFu) << 17;


arr[0] &= ~0xFFu;
arr[0] |= (1 & 0xFFu);

arr[1] &= ~0xFFu;
arr[1] |= (2 & 0xFFu);

arr[2] &= ~0xFFu;
arr[2] |= (3 & 0xFFu);

arr[3] &= ~0xFFu;
arr[3] |= (4 & 0xFFu);

arr[4] &= ~0xFFu;
arr[4] |= (5 & 0xFFu);

arr[5] &= ~0xFFu;
arr[5] |= (6 & 0xFFu);

arr[6] &= ~0xFFu;
arr[6] |= (7 & 0xFFu);

arr[7] &= ~0xFFu;
arr[7] |= (8 & 0xFFu);

arr[8] &= ~0xFFu;
arr[8] |= (9 & 0xFFu);

arr[9] &= ~0xFFu;
arr[9] |= (10 & 0xFFu);

arr[10] &= ~0xFFu;
arr[10] |= (11 & 0xFFu);

arr[11] &= ~0xFFu;
arr[11] |= (12 & 0xFFu);

arr[12] &= ~0xFFu;
arr[12] |= (13 & 0xFFu);

arr[13] &= ~0xFFu;
arr[13] |= (14 & 0xFFu);

arr[14] &= ~0xFFu;
arr[14] |= (15 & 0xFFu);

arr[15] &= ~0xFFu;
arr[15] |= (16 & 0xFFu);

arr[16] &= ~0xFFu;
arr[16] |= (17 & 0xFFu);

arr[17] &= ~0xFFu;
arr[17] |= (18 & 0xFFu);

arr[18] &= ~0xFFu;
arr[18] |= (19 & 0xFFu);

arr[19] &= ~0xFFu;
arr[19] |= (20 & 0xFFu);

arr[20] &= ~0xFFu;
arr[20] |= (21 & 0xFFu);

arr[21] &= ~0xFFu;
arr[21] |= (22 & 0xFFu);

arr[22] &= ~0xFFu;
arr[22] |= (23 & 0xFFu);

arr[23] &= ~0xFFu;
arr[23] |= (24 & 0xFFu);

arr[24] &= ~0xFFu;
arr[24] |= (25 & 0xFFu);

arr[25] &= ~0xFFu;
arr[25] |= (26 & 0xFFu);

arr[26] &= ~0xFFu;
arr[26] |= (27 & 0xFFu);

arr[27] &= ~0xFFu;
arr[27] |= (28 & 0xFFu);

arr[28] &= ~0xFFu;
arr[28] |= (29 & 0xFFu);

arr[29] &= ~0xFFu;
arr[29] |= (30 & 0xFFu);

arr[30] &= ~0xFFu;
arr[30] |= (31 & 0xFFu);

arr[31] &= ~0xFFu;
arr[31] |= (32 & 0xFFu);

arr[32] &= ~0xFFu;
arr[32] |= (33 & 0xFFu);

assert(*len >= 33);
*len = 33;
}

void arinc429_pack_DataForKRP_checksum(const struct DataForKRP *o, uint32_t *arr, unsigned int len)
{

uint32_t tmp_word;

assert(len >= 33);

memcpy(&tmp_word, &o->Checksum, sizeof(tmp_word));
arr[32] &= ~(0x7FFFFFu << 8);
arr[32] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[31] &= ~(0x1FFu << 17);
arr[31] |= (tmp_word & 0x1FFu) << 17;

}

