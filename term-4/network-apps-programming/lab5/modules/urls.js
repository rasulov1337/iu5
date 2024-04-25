import {accessToken, userAccesToken, version} from "./consts.js";



class Urls {
    constructor() {
        this.url = 'https://api.vk.com/method'
        this.commonInfo = `access_token=${accessToken}&v=${version}`
    }

    getUserInfo(userId) {
        return `${this.url}/users.get?user_ids=${userId}&fields=photo_400_orig&${this.commonInfo}`
    }

    getGroupMembers(groupId, sort) {
        return `${this.url}/groups.getMembers?group_id=${groupId}&fields=photo_400_orig&${this.commonInfo}&sort=${sort}`
    }

    getFriendsList(id) {
        return `${this.url}/friends.get?user_id=${id}&access_token=${userAccesToken}&v=${version}&fields=nickname,domain,sex,city,photo_200_orig`
    }


}

export const urls = new Urls()