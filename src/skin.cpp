#include "util.h"
#include "skin.h"


Skin::Skin(const char* filename)
{
	strcpy(m_path, filename);
	m_file.open(filename, ios::in|ios::binary);

	//read head
	memset(&m_head, 0, sizeof(m_head));
	m_file.seekg(0);
	m_file.read((char *)&m_head, sizeof(m_head));

	//read vertices
	m_file.seekg(m_head.vertOffset);
	for(int i = 0; i < m_head.vertNum; i++)
		m_vertList.push_back(readSkinVert(i));

	//read meshs	
	m_file.seekg(m_head.meshOffset);
	for(int i = 0; i < m_head.meshNum; i++)
		m_meshList.push_back(readSkinMesh(i));

	//read material
	m_file.seekg(m_head.mtlOffset);
	for(int i = 0; i < m_head.mtlNum; i++)
		m_mtlList.push_back(readMaterial(i));

}


Skin::~Skin()
{
	m_file.close();
}


void Skin::showHeadInfo()
{
	cout << "=================================================" << endl;
	cout << "[Head]" << m_path << endl;
    cout << "Lable      " << hex << showbase << m_head.Lable       << endl; 
    cout << "Version    " << dec << showbase << (int)m_head.Version     << endl; 
    cout << "vertType   " << dec << showbase << (int)m_head.vertType    << endl; 
    cout << "vertNum    " << dec << showbase << m_head.vertNum     << endl;  
    cout << "vertOffset " << hex << showbase << m_head.vertOffset  << endl; 
    cout << "meshNum    " << dec << showbase << m_head.meshNum     << endl; 
    cout << "meshOffset " << hex << showbase << m_head.meshOffset  << endl; 
    cout << "mtlNum     " << dec << showbase << m_head.mtlNum      << endl; 
    cout << "mtlOffset  " << hex << showbase << m_head.mtlOffset   << endl; 
	cout << "=================================================" << endl;

}


SkinVert Skin::readSkinVert(int i)
{

	SkinVert t;
	m_file.read((char *)&t.pos, sizeof(t.pos));
	m_file.read((char *)&t.normal, sizeof(t.normal));
	//m_file.read((char *)&t.tangent, sizeof(t.tangent));
	//m_file.read((char *)&t.blendWeight, sizeof(t.blendWeight));
	//m_file.read((char *)&t.blendIndices, sizeof(t.blendIndices));
	m_file.read((char *)&t.uv, sizeof(t.uv));

	uint32 n;
	m_file.read((char *)&n, sizeof(n));
	//cout << "[Skin]readSkinVert(" << i << ") bones->" << n << "->";

	//cout << "------ " << n << endl;
	for(int i = 0; i < n; i++)
	{
		SkinBone bone;
		m_file.read((char *)&bone, sizeof(bone));
		t.bones.push_back(bone);
		//cout << " " << bone.boneId << " " << bone.offset.x << " " << bone.offset.y << " " << bone.offset.z << endl;
	}
//	cout << endl;
	
	return t;
}

SkinMesh Skin::readSkinMesh(int idx)
{
	SkinMesh m;
	m_file.read((char *)&m.baseIndex, sizeof(m.baseIndex));
	m_file.read((char *)&m.mtlId, sizeof(m.mtlId));
	m_file.read((char *)&m.vertNum, sizeof(m.vertNum));
	m_file.read((char *)&m.max, sizeof(m.max));
	m_file.read((char *)&m.min, sizeof(m.min));

	uint32 n;
	m_file.read((char *)&n, sizeof(n));
	for(int i = 0; i < n; i++)
	{
		MeshTri t;
		m_file.read((char *)&t, sizeof(t));
		m.baseFaces.push_back(t);
	}
	
	m_file.read((char *)&m.lodNum, sizeof(m.lodNum));
	for(int i = 0; i < 4; i++)
	{
		uint32 n;
		m_file.read((char *)&n, sizeof(n));
		for(int j = 0; j < n; j++)
		{
			MeshTri t;
			m_file.read((char *)&t, sizeof(t));
			m.lodFaces[i].push_back(t);
		}
		if(n > 0)
			cout << "[LLLL]" << m_path << " lodNum " << i << " " << n <<endl;

	}

	cout << "[Skin]readSkinMesh(" << idx << ") base:" << n << " lods: " << m.lodNum << endl;
	
	return m;
}

Material Skin::readMaterial(int i)
{
	cout << "[Skin]readMaterial(" << i << ")" << endl;
	Material m;
	m_file.read((char *)&m, sizeof(m));

 
	for(int t = 0; t < EMap_Max; t++)
	{
		if(strlen(m.map[t])>0 && t > 0)
			cout << "[TTTT]" << m_path << "map" << t << " "<<m.map[t] <<endl;
	}
	
	if(m_meshList[i].baseFaces.size() < 32)
		cout << "[IIII]" << m_path << " mtl "<< i << " " << m.map[0] << " "<<m_meshList[i].baseFaces.size() << endl;

	return m;
}


void Skin::showMaterialInfo()
{
	cout << "[MMMM]"<< m_path << endl;
	int cc = 0;
	for(int i = 0; i < m_mtlList.size(); i++)
	{
		for(int t = 0; t < EMap_Max; t++)
		{
			if(strlen(m_mtlList[i].map[t])>0)
				cc ++;
		}
	}
	cout << dec << "[MMMM]"<< cc << endl;

	for(int i = 0; i < m_mtlList.size(); i++)
	{
		for(int t = 0; t < EMap_Max; t++)
		{
			if(strlen(m_mtlList[i].map[t])>0)
				cout << "[MMMM]" << m_mtlList[i].map[t] <<endl;
		}
	}
}

void Skin::save()
{
	ofstream fout("res/m.skin");

	fout << m_mtlList[0].map[0] << endl;
	fout << endl;
	fout << m_vertList.size() << endl;
	fout << endl;
	for(int i = 0; i < m_vertList.size(); i++)
	{
		SkinVert t = m_vertList[i];
		fout << t.pos.x << " " << t.pos.y << " " << t.pos.z << " " << t.uv.x << " " << t.uv.y << endl;
		fout << t.bones.size() << endl;
		for(int j = 0; j < t.bones.size(); j++)
		{
			SkinBone bone = t.bones[j];
			fout << bone.boneId << " " << bone.weight << endl;
			//fout << bone.boneId << " " << bone.weight << " " << bone.offset.x << " " << bone.offset.y << " " << bone.offset.z << endl;
		}
		fout << endl;
	}
	fout.close();

}


void Skin::calc(Matrix4f * omList[200])
{
	Matrix4f* 	mlist[200] = {0};
	Matrix4f* 	vlist[200] = {0};
	int 		ilist[200] = {0};
	for(int i = 0; i < m_vertList.size(); i++)
	{
		SkinVert v = m_vertList[i];
		for(int j = 0; j < v.bones.size(); j++)
		{
			SkinBone bone = v.bones[j];
			if(omList[bone.boneId] == 0)
			{
				int idx  = ilist[bone.boneId];
				if(idx >= 4)
					continue;

				Matrix4f* mMat;
				Matrix4f* vMat;
				if(mlist[bone.boneId] == 0)
				{
					mMat = new Matrix4f();
					mlist[bone.boneId] = mMat;
					vMat = new Matrix4f();
					vlist[bone.boneId] = vMat;
				}else
				{
					mMat = mlist[bone.boneId];
					vMat = vlist[bone.boneId];
				}

				int t = 0;
				for(t = 0; t < idx; t++)
				{
					float dx = v.pos.x - mMat->c[t][0];
					float dy = v.pos.y - mMat->c[t][1];
					float dz = v.pos.z - mMat->c[t][2];
					if(dx * dx + dy * dy + dz * dz < 1)
						break;
				}
				if(t < idx)
					continue;


				ilist[bone.boneId] = idx + 1;

				mMat->c[idx][0] = v.pos.x;
				mMat->c[idx][1] = v.pos.y;
				mMat->c[idx][2] = v.pos.z;
				mMat->c[idx][3] = 1;
				
				vMat->c[idx][0] = bone.offset.x;
				vMat->c[idx][1] = bone.offset.y;
				vMat->c[idx][2] = bone.offset.z;
				vMat->c[idx][3] = 1;
			}
		}
	}

	for(int i = 0; i < 200; i++)
	{
		Matrix4f* mMat;
		Matrix4f* vMat;
		mMat = mlist[i];
		vMat = vlist[i];

		if(mMat && vMat && omList[i] == 0 && ilist[i] >= 4)
		{
			omList[i] = new Matrix4f((*vMat) * (mMat->inverted()));
		}
		if(mMat) delete mMat;
		if(vMat) delete vMat;
	}
}




