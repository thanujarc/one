/* -------------------------------------------------------------------------- */
/* Copyright 2002-2012, OpenNebula Project Leads (OpenNebula.org)             */
/*                                                                            */
/* Licensed under the Apache License, Version 2.0 (the "License"); you may    */
/* not use this file except in compliance with the License. You may obtain    */
/* a copy of the License at                                                   */
/*                                                                            */
/* http://www.apache.org/licenses/LICENSE-2.0                                 */
/*                                                                            */
/* Unless required by applicable law or agreed to in writing, software        */
/* distributed under the License is distributed on an "AS IS" BASIS,          */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   */
/* See the License for the specific language governing permissions and        */
/* limitations under the License.                                             */
/* -------------------------------------------------------------------------- */

#include "ImageTemplate.h"

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

vector<string> ImageTemplate::restricted_attributes;

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

void ImageTemplate::set_restricted_attributes(vector<const Attribute *>& rattrs)
{
    const SingleAttribute * sattr;
	string attr;

    for (unsigned int i = 0 ; i < rattrs.size() ; i++ )
    {
        sattr = static_cast<const SingleAttribute *>(rattrs[i]);

        attr = sattr->value();
        transform (attr.begin(),attr.end(),attr.begin(),(int(*)(int))toupper);

    	restricted_attributes.push_back(attr);
    }
}

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */